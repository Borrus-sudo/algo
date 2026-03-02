import tkinter as tk
from tkinter import ttk
import networkx as nx
import matplotlib.pyplot as plt
from queue import PriorityQueue
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


edges = {
    "arad": [("zerind", 75), ("sibiu", 140), ("timisoara", 118)],
    "zerind": [("oradea", 71)],
    "oradea": [("sibiu", 151)],
    "sibiu": [("fagaras", 99), ("rimnicu vilcea", 80)],
    "fagaras": [("bucharest", 211)],
    "rimnicu vilcea": [("pitesti", 97), ("craiova", 146)],
    "pitesti": [("bucharest", 101)],
    "timisoara": [("lugoj", 111)],
    "lugoj": [("mehadia", 70)],
    "mehadia": [("dobreta", 75)],
    "dobreta": [("craiova", 120)],
    "craiova": [("pitesti", 138)],
    "bucharest": [("giurgiu", 90), ("urziceni", 85)],
    "urziceni": [("hirsova", 98), ("vaslui", 142)],
    "hirsova": [("eforie", 86)],
    "vaslui": [("iasi", 92)],
    "iasi": [("neamt", 87)],
    "neamt": [],
}

heuristic = {
    "arad": 366,
    "bucharest": 0,
    "craiova": 160,
    "dobreta": 242,
    "eforie": 161,
    "fagaras": 178,
    "giurgiu": 77,
    "hirsova": 151,
    "iasi": 226,
    "lugoj": 244,
    "mehadia": 241,
    "neamt": 234,
    "oradea": 380,
    "pitesti": 98,
    "rimnicu vilcea": 193,
    "sibiu": 253,
    "timisoara": 329,
    "urziceni": 80,
    "vaslui": 199,
    "zerind": 374,
}


def astar(graph, src, log):
    target = "bucharest"

    pq = PriorityQueue()
    parent = {}
    dist = {}

    pq.put((heuristic[src], src))

    for node in graph.nodes:
        dist[node] = 100000000

    dist[src] = 0
    log(f"Start at {src}")

    while not pq.empty():
        f, node = pq.get()
        g = f - heuristic[node]

        if g > dist[node]:
            continue

        log(f"Expanding {node}")

        if node == target:
            break

        for neighbor in graph.neighbors(node):
            w = graph[node][neighbor]["weight"]
            gprime = g + w

            if gprime < dist[neighbor]:
                dist[neighbor] = gprime
                parent[neighbor] = node
                fprime = gprime + heuristic[neighbor]
                pq.put((fprime, neighbor))
                log(f"  Updating {neighbor}")

    path = []
    cur = target
    while cur != src:
        path.append(cur)
        cur = parent[cur]
    path.append(src)
    path.reverse()

    log(f"Path: {' -> '.join(path)}")
    log(f"Total cost: {dist[target]}")

    return path, dist[target]


class GraphApp:
    def __init__(self, root):
        self.root = root
        root.title("A* Search")

        root.columnconfigure(0, weight=1)
        root.columnconfigure(1, weight=3)
        root.rowconfigure(0, weight=1)

        left = ttk.Frame(root)
        left.grid(row=0, column=0, sticky="nsew", padx=5, pady=5)
        left.rowconfigure(1, weight=1)

        ttk.Label(left, text="Source City").pack(anchor="w")
        self.src = tk.StringVar(value="arad")
        self.city_box = ttk.Combobox(
            left,
            textvariable=self.src,
            values=sorted(filter(lambda city: city != "bucharest", heuristic.keys())),
            state="readonly",
        )
        self.city_box.pack(fill="x")
        self.city_box.bind("<<ComboboxSelected>>", lambda e: self.render())

        self.log_box = tk.Text(left, height=12)
        self.log_box.pack(fill="both", expand=True, pady=5)

        self.fig, self.ax = plt.subplots(figsize=(7, 7))
        self.canvas = FigureCanvasTkAgg(self.fig, master=root)
        self.canvas.get_tk_widget().grid(row=0, column=1, sticky="nsew", padx=5, pady=5)

        self.render()

    def log(self, msg):
        self.log_box.insert(tk.END, msg + "\n")
        self.log_box.see(tk.END)

    def render(self):
        self.ax.clear()
        self.log_box.delete("1.0", tk.END)

        G = nx.Graph()
        for u, e in edges.items():
            for v, w in e:
                G.add_edge(u, v, weight=w)

        pos = nx.spring_layout(G, seed=42)

        src = self.src.get()
        if src not in G.nodes:
            self.ax.set_title("Invalid source city")
            self.canvas.draw()
            return

        path, _ = astar(G, src, self.log)
        path_edges = list(zip(path, path[1:]))

        nx.draw(
            G,
            pos,
            ax=self.ax,
            with_labels=True,
            node_size=1400,
            font_size=9,
            edge_color="lightgray",
        )

        nx.draw_networkx_edges(
            G, pos, edgelist=path_edges, edge_color="red", width=3, ax=self.ax
        )

        nx.draw_networkx_edge_labels(
            G, pos, edge_labels=nx.get_edge_attributes(G, "weight"), ax=self.ax
        )

        self.canvas.draw()


if __name__ == "__main__":
    root = tk.Tk()
    root.geometry("1100x700")
    GraphApp(root)
    root.mainloop()
