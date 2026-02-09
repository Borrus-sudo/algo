import tkinter as tk
from tkinter import ttk
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


class GraphApp:
    def __init__(self, root):
        self.root = root
        root.title("NetworkX Graph Playground")

        container = ttk.Frame(root)
        container.pack(fill="both", expand=True)
        container.columnconfigure(0, weight=1)
        container.columnconfigure(1, weight=3)
        container.rowconfigure(0, weight=1)

        left = ttk.Frame(container)
        left.grid(row=0, column=0, sticky="nsew", padx=5, pady=5)
        left.rowconfigure(0, weight=1)

        self.text = tk.Text(left, width=30)
        self.text.grid(row=0, column=0, sticky="nsew")

        self.text.insert(
            "1.0",
            "A B\nB C 3\nC D 1.5\nA D"
        )

        options = ttk.Frame(left)
        options.grid(row=1, column=0, sticky="w", pady=5)

        self.graph_type = tk.StringVar(value="undirected")

        ttk.Label(options, text="Graph type:").pack(anchor="w")

        ttk.Radiobutton(
            options,
            text="Undirected",
            value="undirected",
            variable=self.graph_type,
            command=self.render_graph,
        ).pack(anchor="w")

        ttk.Radiobutton(
            options,
            text="Directed",
            value="directed",
            variable=self.graph_type,
            command=self.render_graph,
        ).pack(anchor="w")

        self.show_labels = tk.BooleanVar(value=True)

        ttk.Checkbutton(
            options,
            text="Show edge labels (weights)",
            variable=self.show_labels,
            command=self.render_graph,
        ).pack(anchor="w", pady=(5, 0))

        ttk.Button(
            left,
            text="Render Graph",
            command=self.render_graph
        ).grid(row=2, column=0, sticky="ew", pady=5)

        self.fig, self.ax = plt.subplots(figsize=(6, 6))
        self.canvas = FigureCanvasTkAgg(self.fig, master=container)
        self.canvas.get_tk_widget().grid(
            row=0, column=1, sticky="nsew", padx=5, pady=5
        )

        self.render_graph()

    def render_graph(self):
        self.ax.clear()

        G = nx.DiGraph() if self.graph_type.get() == "directed" else nx.Graph()

        raw = self.text.get("1.0", tk.END).strip().splitlines()
        for line in raw:
            parts = line.split()
            if len(parts) == 2:
                u, v = parts
                G.add_edge(u, v)
            elif len(parts) == 3:
                u, v, w = parts
                G.add_edge(u, v, label=(w))
            else: 
                print("Parsing error :(")
            

        pos = nx.spring_layout(G, seed=42)

        nx.draw(
            G,
            pos,
            ax=self.ax,
            with_labels=True,
            node_size=1500,
            font_size=10,
            arrows=self.graph_type.get() == "directed",
        )

        if self.show_labels.get():
            edge_labels = nx.get_edge_attributes(G, "label")
            nx.draw_networkx_edge_labels(
                G,
                pos,
                edge_labels=edge_labels,
                ax=self.ax,
            )

        self.canvas.draw()


if __name__ == "__main__":
    root = tk.Tk()
    root.geometry("900x600")
    app = GraphApp(root)
    root.mainloop()
