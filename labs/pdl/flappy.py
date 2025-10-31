import random
import sys


# components

class Velocity:
    def __init__(self, dx: int, dy: int):
        self.dx = dx
        self.dy = dy


class Movement:
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
        if x == 0 or x == self.width - 1:
            return "+"
        elif y == 0 or y == self.height - 1:
            return "-"
        else:
            return " "


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

SCREENW = 150
SCREENH = 35
STARTX = 20
STARTY = 10


# systems
def physics(locs: list[Movement]):
    # check for out-of-bounds, collision and user input
    # I know that the collision can only occur between bird and pipes, so we can exploit that
    # Once something goes out of screen, we put it just outside the edge of the screen from the other side
    # We exploit that fact that pipes never collide and their equi-spacing and equi-speed to our fullest advantage
    birdLoc = locs[0]
    for loc in locs[1:]:
        # check for collision!
        pass
    # out of screen check
    # defo takes advantage of the structure of the game
    for loc in locs[1:]:
        if loc.x + loc.width < STARTX:
            # well now I know this is for sure outta the screen
            loc.x = SCREENW


def render(meshes: list[Mesh], locs: list[Movement], Screen: Screen):

    print(
        "\033[H\033[J", end="", flush=True
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
                    Screen.canvas[loc.y + y - screen.startY][
                        loc.x + x - screen.startX
                    ] = mesh.fetchLexeme(x, y)

    offset = "\n" * Screen.startY
    print(offset)

    # write code to limit in case the screen width exceeds the terminal width?
    for row in range(len(Screen.canvas)):
        line = " " * Screen.startX
        for col in range(len(Screen.canvas[0])):
            line += Screen.canvas[row][col]
            Screen.canvas[row][col] = " "  # blanking the canvas for the next render
        print(line, flush=False)  # keep buffering till it is asked to

    sys.stdout.flush()


def update(loc: list[Movement], vels: list[Velocity]):
    for item, vel in zip(loc, vels):
        item.x += vel.dx
        item.y += vel.dy


# entities

loc: list[Movement] = []
mesh: list[Mesh] = []
vel: list[Velocity] = []
screen = Screen(STARTX, STARTY, SCREENW, SCREENH)


# main code


def init():
    # one bird
    BIRDH = 3
    BIRDW = 10
    BIRDX = STARTX + 5  # 10 is the offset
    BIRDY = STARTY + int(SCREENH / 2) - int(BIRDH / 2)
    BIRDDX = 0
    BIRDDY = 2
    loc.append(Movement(BIRDX, BIRDY, BIRDW, BIRDH))
    mesh.append(Mesh(BIRDW, BIRDH))
    vel.append(Velocity(BIRDDX, BIRDDY))

    # create 20 pipes, 2 each on a x
    PIPEX = STARTX + 20  # offset
    PIPEY = STARTY

    PIPEDX = -5
    PIPEDY = 0

    safeSpace = BIRDH + 10
    totalHeight = SCREENH - safeSpace
    MINPIPEH = int(totalHeight / 4)
    MAXPIPEH = int(totalHeight * 3 / 4)
    PIPEW = 20

    for _ in range(10):

        # pipe1 + pipe2 = totalHeight
        PIPE1H = random.randint(MINPIPEH, MAXPIPEH)
        PIPE2H = totalHeight - PIPE1H

        loc.append(Movement(PIPEX, PIPEY, PIPEW, PIPE1H))
        mesh.append(Mesh(PIPEW, PIPE1H))
        vel.append(Velocity(PIPEDX, PIPEDY))

        loc.append(Movement(PIPEX, PIPEY + PIPE1H + safeSpace, PIPEW, PIPE2H))
        mesh.append(Mesh(PIPEW, PIPE2H))
        vel.append(Velocity(PIPEDX, PIPEDY))

        PIPEX += PIPEW + 25


def loop(fps):
    # after every sometime you know?
    idx = 0
    while True:
        if idx == 0:
            render(mesh, loc, screen)
            update(loc, vel)
        idx += 1
        idx %= fps


if __name__ == "__main__":
    init()
    loop(4000000)
