import random
import sys
import msvcrt

# components


class Velocity:
    def __init__(self, dx: int, dy: int):
        self.dx = dx
        self.dy = dy


class Dimensions:
    def __init__(self, x: int, y: int, width: int, height: int):
        self.x = x
        self.y = y
        self.width = width
        self.height = height


# more like a rectangle mesh
class Mesh:
    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height

    def fetchLexeme(self, x: int, y: int) -> str:
        # very hacky
        if y == 0 or y == self.height - 1:
            return "="
        elif x == 0 or x == self.width - 1:
            return "|"
        else:
            return "\033[44m \033[0m"


class Pipe(Mesh):

    def __init__(self, width: int, height: int):
        super().__init__(width, height)

    def fetchLexeme(self, x: int, y: int) -> str:
        # very hacky
        if y == 0 or y == self.height - 1:
            return "="
        elif x == 0 or x == self.width - 1:
            return "|"
        else:
            return "\033[42m \033[0m"


class Bird(Mesh):
    frames: list[list[list[str]]] = [
        [
            [" ", " ", " ", "_", " ", " ", " "],
            ["_", "_", "(", ".", ")", "<", " "],
            ["\\", "_", "_", "_", ")", " ", " "],
        ],
        [
            [" ", " ", " ", "-", " ", " ", " "],
            ["_", "_", "(", ".", ")", "/", "<"],
            ["\\", "-", "\\", "_", ")", " ", " "],
        ],
    ]
    curr = 1

    ## 33 m
    def __init__(self):
        super().__init__(len(self.frames[0][0]), len(self.frames[0]))

    # works assuming that the whole frame is re-rendered every time
    def fetchLexeme(self, x: int, y: int) -> str:
        if x == 0 and y == 0:
            self.curr += 1
            self.curr %= 2
        lexeme = self.frames[self.curr][y][x]
        if lexeme == " ":
            return f"\033[44m{lexeme}\033[0m"
        else:
            return f"\033[43m{lexeme}\033[0m"


class Screen:
    canvas: list[list[str]] = []

    def __init__(self, startX: int, startY: int, width: int, height: int):
        self.startX = startX
        self.startY = startY
        self.width = width
        self.height = height

        for _ in range(height):
            self.canvas.append([" " for _ in range(width)])


# screen constants

SCREENW = 120
SCREENH = 35
STARTX = 50
STARTY = 5
SCORE = 0.0  # prolly not the right way to do it


# systems
def physics(locs: list[Dimensions]):
    # check for out-of-bounds, collision and user input
    # I know that the collision can only occur between bird and pipes, so we can exploit that
    # Once something goes out of screen, we put it just outside the edge of the screen from the other side
    # We exploit that fact that pipes never collide and their equi-spacing and equi-speed to our fullest advantage
    def isColliding(box1: Dimensions, box2: Dimensions):
        # how to take input properly?
        if (
            box1.x <= box2.x + box2.width
            and box1.x + box1.width >= box2.x
            and box1.y <= box2.y + box2.height - 1
            and box1.y + box1.height - 1 >= box2.y
        ):
            # print("\033[H\033[J", end="", flush=True)
            print(
                " " * STARTX, "Game over :("
            )  # introduce a make the Scene component more capable?
            print(" " * STARTX, "Your final score was ", SCORE)
            exit()

    birdLoc = locs[1]
    for loc in locs[2:]:
        isColliding(birdLoc, loc)

    # out of screen check
    # defo takes advantage of the structure of the game

    global SCORE
    for loc in locs[1:]:
        if loc.x + loc.width < STARTX:
            # well now I know this is for sure outta the screen
            SCORE += 0.5
            loc.x = SCREENW + 60


def render(meshes: list[Mesh], locs: list[Dimensions], Screen: Screen):

    print(
        "\033[H\033[J", end=""
    )  # ANSI code for clearing the screen and taking the cursor to the top left
    for mesh, loc in zip(meshes, locs):
        # only if something is within the screen?
        # as soon as something goes out of the screen completely (that is a pipe basically), we need to give it new coords
        for x in range(0, mesh.width):
            for y in range(0, mesh.height):
                tX = loc.x + x
                tY = loc.y + y
                # within bounds check
                if (
                    tX >= screen.startX
                    and tX < screen.startX + screen.width
                    and tY >= screen.startY
                    and tY < screen.startY + screen.height
                ):
                    output = mesh.fetchLexeme(x, y)
                    if output != " ":
                        Screen.canvas[loc.y + y - screen.startY][
                            loc.x + x - screen.startX
                        ] = output

    output = "\n" * Screen.startY

    # write code to limit in case the screen width exceeds the terminal width?
    print(output)
    print(" " * STARTX, "\033[1mYOUR SCORE\033[0m", SCORE)  # f"\033[1m{lexeme}\033[0m"
    print("\n")
    for row in range(len(Screen.canvas)):
        line = " " * Screen.startX + "".join(Screen.canvas[row])
        sys.stdout.write(line + "\n")
    sys.stdout.flush()

    for row in range(len(Screen.canvas)):
        for col in range(len(Screen.canvas[0])):
            Screen.canvas[row][col] = " "  # blanking the canvas for the next render


def update(loc: list[Dimensions], vels: list[Velocity]):
    for item, vel in zip(loc, vels):
        item.x += vel.dx
        item.y += vel.dy


# key logging system
def key_press(bird: Dimensions):
    if msvcrt.kbhit():
        msvcrt.getch()
        bird.y -= 5  # to account for the gravity


def was_pressed():
    if msvcrt.kbhit():
        msvcrt.getch()
        return True
    return False


# entities

loc: list[Dimensions] = []
mesh: list[Mesh] = []
vel: list[Velocity] = []
screen = Screen(STARTX, STARTY, SCREENW, SCREENH)


# main code


def init():
    # bounding box
    loc.append(Dimensions(STARTX, STARTY, SCREENW, SCREENH))
    mesh.append(Mesh(SCREENW, SCREENH))
    vel.append(Velocity(0, 0))

    # one bird
    BIRDH = 3
    BIRDW = 7
    BIRDX = STARTX + 5  # 10 is the offset
    BIRDY = STARTY + int(SCREENH / 2) - int(BIRDH / 2)
    BIRDDX = 0
    BIRDDY = 2
    loc.append(Dimensions(BIRDX, BIRDY, BIRDW, BIRDH))
    mesh.append(Bird())
    vel.append(Velocity(BIRDDX, BIRDDY))

    PIPEX = STARTX + 40  # offset
    PIPEY = STARTY

    PIPEDX = -5
    PIPEDY = 0

    safeSpace = BIRDH + 10
    totalHeight = SCREENH - safeSpace
    MINPIPEH = int(totalHeight / 4)
    MAXPIPEH = int(totalHeight * 3 / 4)
    PIPEW = 15

    for _ in range(4):

        # PIPE1H + PIPE2H = totalHeight
        PIPE1H = random.randint(MINPIPEH, MAXPIPEH)
        PIPE2H = totalHeight - PIPE1H

        loc.append(Dimensions(PIPEX, PIPEY, PIPEW, PIPE1H))
        mesh.append(Pipe(PIPEW, PIPE1H))
        vel.append(Velocity(PIPEDX, PIPEDY))

        loc.append(Dimensions(PIPEX, PIPEY + PIPE1H + safeSpace, PIPEW, PIPE2H))
        mesh.append(Pipe(PIPEW, PIPE2H))
        vel.append(Velocity(PIPEDX, PIPEDY))

        PIPEX += PIPEW + 25


def loop(fps):
    idx = 0
    while True:
        if idx == 0:
            # the order of these functions very important!
            physics(loc)
            key_press(loc[1])
            update(loc, vel)
            render(mesh, loc, screen)
        idx += 1
        idx %= fps


if __name__ == "__main__":
    init()
    startScreen = """
                                                            ________  __                                                _______   __                  __ 
                                                            |        \\|  \\                                              |       \\ |  \\                |  \\
                                                            | $$$$$$$$| $$  ______    ______    ______   __    __       | $$$$$$$\\ \\$$  ______    ____| $$
                                                            | $$__    | $$ |      \\  /      \\  /      \\ |  \\  |  \\      | $$__/ $$|  \\ /      \\  /      $$
                                                            | $$  \\   | $$  \\$$$$$$\\|  $$$$$$\\|  $$$$$$\\| $$  | $$      | $$    $$| $$|  $$$$$$\\|  $$$$$$$
                                                            | $$$$$   | $$ /      $$| $$  | $$| $$  | $$| $$  | $$      | $$$$$$$\\| $$| $$   \\$$| $$  | $$
                                                            | $$      | $$|  $$$$$$$| $$__/ $$| $$__/ $$| $$__/ $$      | $$__/ $$| $$| $$      | $$__| $$
                                                            | $$      | $$ \\$$    $$| $$    $$| $$    $$ \\$$    $$      | $$    $$| $$| $$       \\$$    $$
                                                             \\$$       \\$$  \\$$$$$$$| $$$$$$$ | $$$$$$$  _\\$$$$$$$       \\$$$$$$$  \\$$ \\$$        \\$$$$$$$
                                                                                    | $$      | $$      |  \\__| $$                                        
                                                                                    | $$      | $$       \\$$    $$                                        
                                                                                     \\$$       \\$$        \\$$$$$$                                         
    """
    print("\033[H\033[J", end="", flush=True)
    print("\n" * STARTY)
    print(startScreen)
    print("\n" * 2)
    print((" " * 90) + "Press any key to start playing!")
    while True:
        if was_pressed():
            break
    loop(3500000)
