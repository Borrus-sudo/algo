import random
import tkinter as tk
import math


class Wumpus:

    VOID = 0
    BREEZE = 1
    STENCH = 2

    PIT = 3
    WUMPUS = 4
    GOLD = 5

    UNKNOWN = 6
    SAFE_TO_VISIT = 7

    curr_pos = None

    def __init__(self, board_size, curr_pos=(0, 0)):
        self.board = [[self.UNKNOWN] * board_size for _ in range(board_size)]
        self.priority = [[-math.inf] * board_size for _ in range(board_size)]
        self.curr_pos = curr_pos

    def getNeighbours(self, pos):
        ub = len(self.board)
        lb = 0
        row, col = pos
        res = []
        if row + 1 < ub:
            res.append((row + 1, col))
        if col + 1 < ub:
            res.append((row, col + 1))
        if row - 1 >= lb:
            res.append((row - 1, col))
        if col - 1 >= lb:
            res.append((row, col - 1))

        return res

    def tell(self, pos, type):
        row, col = pos
        self.board[row][col] = type
        neighbours = self.getNeighbours(pos)
        if self.priority[row][col] == -math.inf:
            self.priority[row][col] = len(neighbours)

        if type == self.VOID:

            for rowPrime, colPrime in neighbours:
                if self.board[rowPrime][colPrime] == self.UNKNOWN:
                    self.board[rowPrime][colPrime] = self.SAFE_TO_VISIT
                    self.priority[rowPrime][colPrime] = len(self.getNeighbours((rowPrime, colPrime)))

        elif type == self.BREEZE:

            pitSeen = False
            unknowns = []
            for rowPrime, colPrime in neighbours:
                if self.board[rowPrime][colPrime] == self.PIT:
                    pitSeen = True
                    break
                if self.board[rowPrime][colPrime] == self.UNKNOWN:
                    unknowns.append((rowPrime, colPrime))

            if pitSeen:
                for rowPrime, colPrime in neighbours:
                    if self.board[rowPrime][colPrime] == self.UNKNOWN:
                        self.board[rowPrime][colPrime] = self.SAFE_TO_VISIT
                        self.priority[rowPrime][colPrime] = len(self.getNeighbours((rowPrime, colPrime)))
            elif len(unknowns) == 1:
                self.tell(unknowns[0], self.PIT)

        elif type == self.STENCH:

            wumpus = False
            unknowns = []

            for rowPrime, colPrime in neighbours:
                if self.board[rowPrime][colPrime] == self.WUMPUS:
                    wumpus = True
                    break
                if self.board[rowPrime][colPrime] == self.UNKNOWN:
                    unknowns.append((rowPrime, colPrime))

            if wumpus:
                for rowPrime, colPrime in neighbours:
                    if self.board[rowPrime][colPrime] == self.UNKNOWN:
                        self.board[rowPrime][colPrime] = self.SAFE_TO_VISIT
                        self.priority[rowPrime][colPrime] = len(
                            self.getNeighbours((rowPrime, colPrime))
                        )

            elif len(unknowns) == 1:
                self.tell(unknowns[0], self.WUMPUS)

        elif type == self.PIT:
            for rowPrime, colPrime in neighbours:
                self.board[rowPrime][colPrime] = self.BREEZE

        elif type == self.WUMPUS:
            for rowPrime, colPrime in neighbours:
                self.board[rowPrime][colPrime] = self.STENCH

    def query(self):
        neighbours = self.getNeighbours(self.curr_pos)

        (currRow, currCol) = self.curr_pos
        self.priority[currRow][currCol] -= 1

        for row, col in neighbours:
            if self.board[row][col] == self.SAFE_TO_VISIT:
                self.curr_pos = (row, col)
                return self.curr_pos

        known_squares = []
        unknown_squares = []
        for row, col in neighbours:
            if (
                self.board[row][col] == self.VOID
                or self.board[row][col] == self.BREEZE
                or self.board[row][col] == self.STENCH
            ):
                known_squares.append((row, col))
            elif self.board[row][col] == self.UNKNOWN:
                unknown_squares.append((row, col))

        known_squares.sort(key=lambda x: -self.priority[x[0]][x[1]])
        unknown_squares.sort(key=lambda x: -self.priority[x[0]][x[1]])

        if len(known_squares):
            rR, rC = known_squares[0]
            if self.priority[rR][rC] > 0:
                self.curr_pos = known_squares[0]
                return self.curr_pos
        if len(unknown_squares):
            self.curr_pos = unknown_squares[0]
            return self.curr_pos
        else:
            self.curr_pos = known_squares[0]
            return self.curr_pos


class WumpusWorld:
    def __init__(self, size):
        self.size = size
        self.board = [[set() for _ in range(size)] for _ in range(size)]

        gr, gc = random.randint(0, size - 1), random.randint(0, size - 1)
        self.board[gr][gc].add(Wumpus.GOLD)

        while True:
            wr, wc = random.randint(0, size - 1), random.randint(0, size - 1)
            if (wr, wc) != (gr, gc):
                self.board[wr][wc].add(Wumpus.WUMPUS)
                break

        for row in range(size):
            for col in range(size):
                if (row, col) == (gr, gc) or (row, col) == (wr, wc):
                    continue

                if random.random() < 0.2:
                    self.board[row][col].add(Wumpus.PIT)

        for row in range(size):
            for col in range(size):
                if Wumpus.PIT in self.board[row][col]:
                    for rowPrime, colPrime in self.getNeighbours((row, col)):
                        if (
                            Wumpus.GOLD not in self.board[rowPrime][colPrime]
                            and Wumpus.WUMPUS not in self.board[rowPrime][colPrime]
                        ):
                            self.board[rowPrime][colPrime].add(Wumpus.BREEZE)

                if Wumpus.WUMPUS in self.board[row][col]:
                    for rowPrime, colPrime in self.getNeighbours((row, col)):
                        if (
                            Wumpus.GOLD not in self.board[rowPrime][colPrime]
                            and Wumpus.PIT not in self.board[rowPrime][colPrime]
                        ):
                            self.board[rowPrime][colPrime].add(Wumpus.STENCH)

        for row in range(size):
            for col in range(size):
                cell = self.board[row][col]

                if Wumpus.GOLD in cell:
                    self.board[row][col] = {Wumpus.GOLD}
                    continue

                if Wumpus.PIT in cell:
                    self.board[row][col].discard(Wumpus.STENCH)
                    self.board[row][col].discard(Wumpus.BREEZE)

                if Wumpus.WUMPUS in cell:
                    self.board[row][col].discard(Wumpus.BREEZE)

                if Wumpus.BREEZE in cell and Wumpus.STENCH in cell:
                    self.board[row][col].discard(Wumpus.STENCH)
        self.print_board()

    def print_board(self):
        symbol_map = {
            Wumpus.GOLD: "G",
            Wumpus.WUMPUS: "W",
            Wumpus.PIT: "P",
            Wumpus.BREEZE: "B",
            Wumpus.STENCH: "S",
            Wumpus.VOID: ".",
        }

        print("\nWumpus World:\n")

        for row in range(self.size):
            row_str = []
            for col in range(self.size):
                cell = self.board[row][col]

                if not cell:
                    row_str.append(".")
                else:
                    # Join symbols in sorted order for consistency
                    symbols = "".join(sorted(symbol_map[item] for item in cell))
                    row_str.append(symbols)

            print(" | ".join(f"{x:3}" for x in row_str))
        print()

    def getNeighbours(self, pos):
        row, col = pos
        res = []

        if row + 1 < self.size:
            res.append((row + 1, col))
        if col + 1 < self.size:
            res.append((row, col + 1))
        if row - 1 >= 0:
            res.append((row - 1, col))
        if col - 1 >= 0:
            res.append((row, col - 1))

        return res

    def sense(self, pos):
        cell = self.board[pos[0]][pos[1]]

        if Wumpus.GOLD in cell:
            return Wumpus.GOLD
        if Wumpus.PIT in cell:
            return Wumpus.PIT
        if Wumpus.WUMPUS in cell:
            return Wumpus.WUMPUS

        if Wumpus.BREEZE in cell:
            return Wumpus.BREEZE
        if Wumpus.STENCH in cell:
            return Wumpus.STENCH

        return Wumpus.VOID


class UI:
    def __init__(self, size=4):
        self.size = size
        self.world = WumpusWorld(size)
        self.agent = Wumpus(size)

        self.root = tk.Tk()
        self.root.title("Wumpus World")

        self.cells = [[None] * size for _ in range(size)]
        self.game_over = False

        for r in range(size):
            for c in range(size):
                lbl = tk.Label(
                    self.root,
                    text="",
                    width=6,
                    height=3,
                    borderwidth=1,
                    relief="solid",
                    font=("Arial", 14),
                )
                lbl.grid(row=r, column=c)
                self.cells[r][c] = lbl

        self.status = tk.Label(self.root, text="Running...", font=("Arial", 14))
        self.status.grid(row=size, column=0, columnspan=size)

        self.update_ui()
        self.root.after(800, self.step)

    def update_ui(self):
        for r in range(self.size):
            for c in range(self.size):
                txt = ""
                if (r, c) == self.agent.curr_pos:
                    txt += "A\n"

                cell = self.agent.board[r][c]
                mapping = {
                    Wumpus.VOID: "V",
                    Wumpus.BREEZE: "B",
                    Wumpus.STENCH: "S",
                    Wumpus.PIT: "P",
                    Wumpus.WUMPUS: "W",
                    Wumpus.GOLD: "G",
                    Wumpus.SAFE_TO_VISIT: "✔",
                    Wumpus.UNKNOWN: "?",
                }
                txt += mapping.get(cell, "?")
                self.cells[r][c].config(text=txt)

    def end_game(self, msg):
        self.status.config(text=msg)
        self.game_over = True

    def step(self):
        if self.game_over:
            return

        pos = self.agent.curr_pos
        perception = self.world.sense(pos)
        
        if perception == Wumpus.PIT:
            self.update_ui()
            self.end_game("Fell into PIT")
            return

        if perception == Wumpus.WUMPUS:
            self.update_ui()
            self.end_game("Eaten by Wumpus")
            return

        if perception == Wumpus.GOLD:
            self.update_ui()
            self.end_game("Found GOLD")
            return

        self.agent.tell(pos, perception)
        self.agent.query()
        self.update_ui()
        self.root.after(800, self.step)

    def run(self):
        self.root.mainloop()


if __name__ == "__main__":
    UI(4).run()
