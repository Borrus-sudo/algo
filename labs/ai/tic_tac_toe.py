import math
import copy


class SearchAlgo:
    def __init__(self, search_algo, gen, G, hashify=lambda x: x):
        self.search = search_algo
        self.gen = gen
        self.G = G
        self.hashify = hashify
        pass

    def attach_data(node, metadata):
        pass

    def backtrack(node):
        pass

    def see(node, label=None):
        # add the node to graph
        pass

    def link(parent, child):
        pass

    def perform(self, start):
        return self.search(
            start,
            self,
        )


class TicTacToe:
    """
    We give ourselves all the primitives that we need for the game loop!
    """

    # Constants
    VOID = "*"
    TIE = "TIE"
    ON_GOING = "ON_GOING"
    P1 = "X"
    P2 = "O"

    """
    Possible Results: 
    player 1 won, player 2 won, tie or still on-going!
    Does not check the validity of the position. We just expect that you that it is a valid position!
    """

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

        # shit show on the memory, a major one!
        def minmax(start, tools):
            board, curr = start
            # this stuff is not really good for perf, but it's fine ig
            if TicTacToe.eval(board) == TicTacToe.P1:
                return (1, board)
            elif TicTacToe.eval(board) == TicTacToe.P2:
                return (-1, board)
            elif TicTacToe.eval(board) == TicTacToe.TIE:
                return (0, board)
            else:
                if curr is TicTacToe.P1:
                    maxima = -math.inf
                    goto = None
                    for neighbour in tools.gen(start):
                        new_val, _ = minmax((neighbour, TicTacToe.P2), tools)
                        if maxima < new_val:
                            maxima = new_val
                            goto = neighbour
                    return (maxima, goto)
                else:
                    minima = math.inf
                    goto = None
                    for neighbour in tools.gen(start):
                        new_val, _ = minmax((neighbour, TicTacToe.P1), tools)
                        if minima > new_val:
                            minima = new_val
                            goto = neighbour
                    return (minima, goto)

        # this is a total shit show on the memory
        def gen(start):
            board, curr = start
            # curr is a board
            res = []
            dim = len(board)
            for row in range(dim):
                for col in range(dim):
                    if board[row][col] is TicTacToe.VOID:
                        # I can play a move?
                        new_neighbour = copy.deepcopy(board)
                        new_neighbour[row][col] = curr
                        res.append(new_neighbour)
            return res

        ss = SearchAlgo(
            minmax,
            gen,
            G,
            hashify=lambda board: "".join(["".join(row) for row in board]),
        )
        return ss.perform((board, curr))

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

    def updateMove(self, pos):
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
        )  # should also give modify G, prolly not
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


if __name__ == "__main__":
    board = TicTacToe()
    while board.getGameState() is TicTacToe.ON_GOING:
        print(board.board)
        board.updateMove(board.generateNextMove(None))
    print(board.board)
    print(board.getGameState())
