import math
import copy
import networkx as nx
import tkinter as tk
from tkinter import ttk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


class Search:

    @staticmethod
    def layered_layout(G):
        levels = {}
        for node, data in G.nodes(data=True):
            lvl = data.get("depth", 0)
            levels.setdefault(lvl, []).append(node)

        pos = {}
        for lvl, nodes in levels.items():
            for i, node in enumerate(nodes):
                pos[node] = (i / 2, -lvl)

        return pos

    def __init__(self, G):
        self.G = G

    # hashify for when the node is not hashable (cause it is mutable). So we provide a custom hashify function
    def hashify(self, node):
        return node

    def info(self, node, metadata):
        if self.hashify(node) not in self.G.nodes:
            return
        for k, v in metadata.items():
            self.G.nodes[self.hashify(node)][k] = v

    def track(self, node):
        if self.hashify(node) not in self.G.nodes:
            self.G.add_node(self.hashify(node))

    def link(self, parent, child):
        parent_h = self.hashify(parent)
        child_h = self.hashify(child)
        if parent_h in self.G.nodes and child_h in self.G.nodes:
            self.G.add_edge(parent_h, child_h)

    def backtrack(self, node):
        self.G.remove_node(self.hashify(node))

    def getGraph(self):
        return self.G

    def render(self):
        args = {
            "G": self.G,
            "node_color": "lightblue",
            "node_size": 1500,
            "font_size": 8,
            "labels": nx.get_node_attributes(self.G, "labels"),
            "arrows": True,
        }
        return args


class Minmax(Search):
    def __init__(self, G=nx.DiGraph()):
        super().__init__(G)

    def pretty_print(self, board):
        res = ""
        for i in range(3):
            row = " | ".join(board[i])
            res += "\n " + row
            if i < 2:
                res += "\n---+---+---"
        return res

    # shit show on the memory, a major one!
    def generator(self, state):
        board, curr = state
        res = []
        dim = len(board)
        for row in range(dim):
            for col in range(dim):
                if board[row][col] is TicTacToe.VOID:
                    new_neighbour = copy.deepcopy(board)
                    new_neighbour[row][col] = curr
                    res.append(new_neighbour)
        return res

    def search(self, state, alpha=-math.inf, beta=math.inf, depth=0):
        board, turn = state
        if depth < 5:
            self.track(board)
            self.info(board, {"label": self.pretty_print(board), "depth": depth})

        if TicTacToe.eval(board) == TicTacToe.P1:
            return (1, board)
        elif TicTacToe.eval(board) == TicTacToe.P2:
            return (-1, board)
        elif TicTacToe.eval(board) == TicTacToe.TIE:
            return (0, board)
        else:
            if turn is TicTacToe.P1:
                maxima = -math.inf
                goto = None

                for neighbour in self.generator(state):
                    new_val, _ = self.search(
                        (neighbour, TicTacToe.P2), alpha, beta, depth + 1
                    )
                    alpha = max(alpha, new_val)
                    self.link(board, neighbour)
                    if maxima < new_val:
                        maxima = new_val
                        goto = neighbour

                    if beta <= alpha:
                        break

                return (maxima, goto)
            else:
                minima = math.inf
                goto = None

                for neighbour in self.generator(state):
                    new_val, _ = self.search(
                        (neighbour, TicTacToe.P1), alpha, beta, depth + 1
                    )
                    beta = min(beta, new_val)
                    self.link(board, neighbour)
                    if minima > new_val:
                        minima = new_val
                        goto = neighbour
                    if beta <= alpha:
                        break
                return (minima, goto)

    def hashify(self, node):
        return "".join(["".join(row) for row in node])


class TicTacToe:

    # Constants
    VOID = "*"
    TIE = "TIE"
    ON_GOING = "ON_GOING"
    P1 = "X"
    P2 = "O"

    @staticmethod
    def eval(board):
        empty = 0
        dim = len(board)
        for row in range(dim):
            currRow1 = 0
            currRow2 = 0
            for col in range(dim):
                pos = board[row][col]
                if pos == TicTacToe.P1:
                    currRow1 += 1
                elif pos == TicTacToe.P2:
                    currRow2 += 1
                else:
                    empty += 1
            if currRow1 == dim:
                return TicTacToe.P1
            elif currRow2 == dim:
                return TicTacToe.P2

        for col in range(dim):
            currCol1 = 0
            currCol2 = 0
            for row in range(dim):
                pos = board[row][col]

                if pos == TicTacToe.P1:
                    currCol1 += 1
                elif pos == TicTacToe.P2:
                    currCol2 += 1

                if currCol1 == dim:
                    return TicTacToe.P1
                elif currCol2 == dim:
                    return TicTacToe.P2

        # brute forcing for 3x3 cause I am too lazy!
        if board[0][0] == board[1][1] and board[1][1] == board[2][2]:
            if board[1][1] == TicTacToe.P1:
                return TicTacToe.P1
            elif board[1][1] == TicTacToe.P2:
                return TicTacToe.P2

        if board[2][0] == board[1][1] and board[1][1] == board[0][2]:
            if board[1][1] == TicTacToe.P1:
                return TicTacToe.P1
            elif board[1][1] == TicTacToe.P2:
                return TicTacToe.P2

        if empty == 0:
            return TicTacToe.TIE

        return TicTacToe.ON_GOING

    @staticmethod
    def search(board, curr, G):
        ss = Minmax(G)
        return ss.search((board, curr))

    def __init__(self, dim=3):
        ## Game state
        self.dim = dim
        self.board = [
            [TicTacToe.VOID for _ in range(self.dim)] for _ in range(self.dim)
        ]
        self.CURR = TicTacToe.P1

    def switchTurn(self):
        if self.CURR == TicTacToe.P1:
            self.CURR = TicTacToe.P2
        else:
            self.CURR = TicTacToe.P1

    def isValidMove(self, pos):
        row, col = pos
        if self.board[row][col] == TicTacToe.VOID:
            return True
        else:
            return False

    def updateMove(self, pos, playing):
        # Hacky and not performant?
        if self.getGameState() != TicTacToe.ON_GOING:
            return False
        if self.CURR != playing:
            return False
        if not self.isValidMove(pos):
            return False
        row, col = pos
        self.board[row][col] = self.CURR
        self.switchTurn()
        return True

    def getGameState(self):
        return TicTacToe.eval(self.board)

    # has to return a move for self.CURR, apply minmax and alpha beta pruning here!
    def generateNextMove(self, G):
        _, best_next = TicTacToe.search(
            self.board, self.CURR, G
        )  # should not modify G, but it does!
        if best_next is None:
            return (-1, -1)
        for row in range(self.dim):
            for col in range(self.dim):
                if self.board[row][col] != best_next[row][col]:
                    return (row, col)

    def restart(self):
        self.board = [
            [TicTacToe.VOID for _ in range(self.dim)] for _ in range(self.dim)
        ]
        self.CURR = TicTacToe.P1


class Game:
    def __init__(self):

        # Core Game State!
        self.game = TicTacToe()
        self.root = tk.Tk()
        self.buttons = [[None] * 3 for _ in range(3)]
        self.G = nx.DiGraph()

        self.root.title()
        self.root.geometry("1100x600")
        self.root.columnconfigure(0, weight=1)
        self.root.columnconfigure(1, weight=3)
        self.root.rowconfigure(0, weight=1)

        left = ttk.Frame(self.root)
        left.grid(row=0, column=0, sticky="nsew", padx=5, pady=5)

        left.rowconfigure(0, weight=0)
        left.rowconfigure(1, weight=3)
        left.rowconfigure(2, weight=1)
        left.columnconfigure(0, weight=1)

        ttk.Label(
            left, text="Tic Tac Toe: You are 'X' and you go first!", font=("Arial", 16)
        ).grid(row=0, column=0, sticky="n", pady=5)

        board_frame = ttk.Frame(left)
        board_frame.grid(row=1, column=0, padx=10, pady=10, sticky="nsew")

        for row in range(3):
            board_frame.rowconfigure(row, weight=1)
            board_frame.columnconfigure(row, weight=1)

        for row in range(3):
            for col in range(3):
                btn = tk.Button(
                    board_frame,
                    text="",
                    command=lambda row=row, col=col: self.game_update(
                        (row, col), TicTacToe.P1
                    ),
                )
                btn.grid(row=row, column=col, sticky="nsew", padx=2, pady=2)
                self.buttons[row][col] = btn

        self.log_box = tk.Text(left, height=6)
        self.log_box.grid(row=2, column=0, sticky="nsew", pady=5)

        self.fig, self.ax = plt.subplots(figsize=(8, 4))
        self.canvas = FigureCanvasTkAgg(self.fig, master=self.root)
        self.canvas.get_tk_widget().grid(row=0, column=1, sticky="nsew")

    def log(self, msg):
        self.log_box.insert(tk.END, msg + "\n")
        self.log_box.see(tk.END)

    def game_update(self, pos, playing):

        row, col = pos
        playerSymbol = self.game.CURR
        done = self.game.updateMove(pos, playing)
        if not done:
            self.log("Invalid move vro!")
        else:
            self.buttons[row][col].configure(text=playerSymbol)

        curr_state = self.game.getGameState()

        if curr_state == TicTacToe.TIE:
            self.log("Game draw!")
        elif curr_state == TicTacToe.P1:
            self.log("You won!")
        elif curr_state == TicTacToe.P2:
            self.log("You lost!")
        elif self.game.CURR == TicTacToe.P2:
            self.G.clear()
            self.game_update(self.game.generateNextMove(self.G), TicTacToe.P2)
            self.renderGraph()

    def ui(self):
        self.root.mainloop()

    def renderGraph(self):
        self.ax.clear()
        nx.draw(
            G=self.G,
            pos=Search.layered_layout(self.G),
            ax=self.ax,
            node_size=500,
            labels=nx.get_node_attributes(self.G, "label"),
            font_size=8,
            node_color="lightblue",
            arrows=True,
        )
        self.ax.set_title("Minmax TicTacToe")
        self.ax.set_axis_off()
        self.canvas.draw()

if __name__ == "__main__":
    gg = Game()
    gg.ui()
