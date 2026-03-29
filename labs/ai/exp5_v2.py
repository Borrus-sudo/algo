import tkinter as tk
from tkinter import ttk
import random
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


def cost(state):
    c = 0
    n = len(state)
    for i in range(n):
        for j in range(i + 1, n):
            if state[i] == state[j] or abs(state[i] - state[j]) == abs(i - j):
                c += 1
    return c


def print_board(state, n, log):
    log("Final Board:")
    for r in range(n):
        row = []
        for c in range(n):
            row.append("1" if state[c] == r else "0")
        log(" ".join(row))


def random_state(n):
    return tuple(random.randint(0, n - 1) for _ in range(n))


def gen(state):
    n = len(state)
    neighbors = []
    for col in range(n):
        curr_row = state[col]
        for row in range(n):
            if row != curr_row:
                new_state = list(state)
                new_state[col] = row
                new_state = tuple(new_state)
                neighbors.append((new_state, cost(new_state)))
    return neighbors


def hill_climb(log, n):
    G = nx.DiGraph()

    current = random_state(n)
    current_cost = cost(current)

    path = [current]

    G.add_node(current, label=f"{current}\nh={current_cost}", level=0)

    log(f"Start: {current} h={current_cost}")

    level = 0

    while True:
        neighbors = gen(current)

        best = current
        best_cost = current_cost

        for s, c in neighbors:
            if c < best_cost:
                best = s
                best_cost = c

        others = [(s, c) for s, c in neighbors if s != best][:4]

        selected = [(best, best_cost)] + others

        for s, c in selected:
            if s not in G:
                G.add_node(s, label=f"{s}\nh={c}", level=level + 1)
            G.add_edge(current, s, chosen=(s == best))

        if best_cost >= current_cost:
            log("Plateau reached")
            return G, path, False, None

        G[current][best]["chosen"] = True

        current = best
        current_cost = best_cost
        path.append(current)
        level += 1

        log(f"Move to {current} h={current_cost}")

        if current_cost == 0:
            log("Solution found")
            return G, path, True, current


def solve_with_restarts(log, n, max_restarts=20):
    full_G = nx.DiGraph()
    final_path = []

    for i in range(max_restarts):
        G, path, success, final_state = hill_climb(log, n)
        full_G = G
        final_path = path

        if success:
            print_board(final_state, n, log)
            return full_G, final_path

    log("Failed after all restarts")
    return full_G, final_path


def layered_layout(G):
    levels = {}
    for node, data in G.nodes(data=True):
        lvl = data.get("level", 0)
        levels.setdefault(lvl, []).append(node)

    pos = {}
    for lvl, nodes in levels.items():
        for i, node in enumerate(nodes):
            pos[node] = (i / 2, -lvl)

    return pos


class NQueenApp:
    def __init__(self, root):
        self.root = root
        root.title("Hill Climbing N Queens")

        root.columnconfigure(0, weight=1)
        root.columnconfigure(1, weight=2)
        root.rowconfigure(0, weight=1)

        left = ttk.Frame(root)
        left.grid(row=0, column=0, sticky="nsew", padx=5, pady=5)
        left.rowconfigure(2, weight=1)

        ttk.Label(left, text="Board Size").grid(row=0, column=0, sticky="w")

        self.size_var = tk.IntVar(value=8)
        self.size_box = ttk.Combobox(
            left,
            textvariable=self.size_var,
            values=[4, 8],
            state="readonly",
        )
        self.size_box.grid(row=1, column=0, sticky="ew", pady=5)

        self.run_btn = ttk.Button(left, text="Run", command=self.render)
        self.run_btn.grid(row=1, column=1, padx=5)

        self.log_box = tk.Text(left)
        self.log_box.grid(row=2, column=0, columnspan=2, sticky="nsew")

        self.fig, self.ax = plt.subplots(figsize=(8, 5))
        self.canvas = FigureCanvasTkAgg(self.fig, master=root)
        self.canvas.get_tk_widget().grid(row=0, column=1, sticky="nsew")

    def log(self, msg):
        self.log_box.insert(tk.END, msg + "\n")
        self.log_box.see(tk.END)

    def render(self):
        self.ax.clear()
        self.log_box.delete("1.0", tk.END)

        n = self.size_var.get()
        G, path = solve_with_restarts(self.log, n)

        pos = layered_layout(G)

        edge_colors = []
        for u, v, data in G.edges(data=True):
            if data.get("chosen"):
                edge_colors.append("red")
            else:
                edge_colors.append("lightgray")

        nx.draw(
            G,
            pos,
            ax=self.ax,
            node_size=1200,
            node_color="lightblue",
            with_labels=False,
            edge_color=edge_colors,
            arrows=True,
        )

        labels = nx.get_node_attributes(G, "label")

        nx.draw_networkx_labels(
            G,
            pos,
            labels=labels,
            font_size=7,
            ax=self.ax,
        )

        self.ax.set_title("State Space Exploration")
        self.ax.set_axis_off()

        self.canvas.draw()


if __name__ == "__main__":
    root = tk.Tk()
    root.geometry("1100x600")
    app = NQueenApp(root)
    root.mainloop()
