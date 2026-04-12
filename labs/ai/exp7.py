import tkinter as tk
from tkinter import ttk
import random
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


def is_safe(node, color, state, graph):
    for neighbor in graph.neighbors(node):
        if state[neighbor] == color:
            return False
    return True


def graph_coloring_dfs(graph, n_colors, log):
    n = len(graph.nodes)
    state = [-1] * n
    nodes = list(graph.nodes)

    def dfs(index):
        if index == n:
            return True

        node = nodes[index]

        for color in range(n_colors):
            log(f"Trying Node {node} → Color {color}")

            if is_safe(node, color, state, graph):
                state[node] = color
                log(f"Assigned Node {node} → Color {color}")

                if dfs(index + 1):
                    return True

                log(f"Backtracking on Node {node}")
                state[node] = -1
            else:
                log(f"Conflict at Node {node} with Color {color}")

        return False

    success = dfs(0)
    return success, state


def generate_random_graph(n_nodes=6, p=0.4):
    return nx.erdos_renyi_graph(n_nodes, p)


class GraphColoringApp:
    def __init__(self, root):
        self.root = root
        root.title("DFS Graph Coloring")

        root.columnconfigure(0, weight=1)
        root.columnconfigure(1, weight=2)
        root.rowconfigure(0, weight=1)

        left = ttk.Frame(root)
        left.grid(row=0, column=0, sticky="nsew", padx=5, pady=5)
        left.rowconfigure(3, weight=1)

        ttk.Label(left, text="Number of Colors").grid(row=0, column=0, sticky="w")

        self.color_var = tk.IntVar(value=3)
        ttk.Entry(left, textvariable=self.color_var).grid(row=1, column=0, sticky="ew")

        self.run_btn = ttk.Button(left, text="Color Graph", command=self.color_graph)
        self.run_btn.grid(row=1, column=1, padx=5)

        self.gen_btn = ttk.Button(
            left, text="Generate Graph", command=self.generate_graph_ui
        )
        self.gen_btn.grid(row=2, column=0, columnspan=2, pady=5)

        self.log_box = tk.Text(left)
        self.log_box.grid(row=3, column=0, columnspan=2, sticky="nsew")

        self.fig, self.ax = plt.subplots(figsize=(8, 4))
        self.canvas = FigureCanvasTkAgg(self.fig, master=root)
        self.canvas.get_tk_widget().grid(row=0, column=1, sticky="nsew")

        self.graph = None
        self.pos = None

        self.generate_graph_ui()

    def log(self, msg):
        self.log_box.insert(tk.END, msg + "\n")
        self.log_box.see(tk.END)

    def generate_graph_ui(self):
        self.ax.clear()
        self.log_box.delete("1.0", tk.END)

        self.graph = generate_random_graph(n_nodes=6)
        self.pos = nx.spring_layout(self.graph)

        nx.draw(
            self.graph,
            self.pos,
            with_labels=True,
            node_color="lightgray",
            node_size=1000,
            ax=self.ax,
        )

        self.ax.set_title("Uncolored Graph")
        self.canvas.draw()

        self.log("Generated Graph Edges:")
        for edge in self.graph.edges():
            self.log(str(edge))

    def color_graph(self):
        if self.graph is None:
            return

        self.ax.clear()

        n_colors = self.color_var.get()

        success, state = graph_coloring_dfs(self.graph, n_colors, self.log)

        if success:
            self.log("\nSolution Found:")
            for i, c in enumerate(state):
                self.log(f"Node {i} → Color {c}")
        else:
            self.log("\nNo solution exists")

        color_map = []
        for node in self.graph.nodes:
            if state[node] == -1:
                color_map.append("gray")
            else:
                color_map.append(state[node])

        nx.draw(
            self.graph,
            self.pos,
            with_labels=True,
            node_color=color_map,
            node_size=1000,
            ax=self.ax,
        )

        self.ax.set_title("Colored Graph")
        self.canvas.draw()


if __name__ == "__main__":
    root = tk.Tk()
    root.geometry("1100x600")
    app = GraphColoringApp(root)
    root.mainloop()
