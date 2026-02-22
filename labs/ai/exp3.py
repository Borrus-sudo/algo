import tkinter as tk
from tkinter import ttk
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from collections import deque


class SearchSpace:
    
    def __init__(self, a, b, target):
        self.a = a
        self.b = b
        self.target = target
        
        self.visited = {}
        self.edges = []
        
        self.dfs_visited = {}
        self.dfs_edges = []
        self.dfs_colors = {}
        
        self.bfs_visited = {}
        self.bfs_edges = []
        self.bfs_colors = {}
        
        
    # Actions: 
    # 1) Fill the jug A
    # 2) Fill the jug B
    # 3) Fill from jug A to jug B uptill capacity
    # 4) Fill from jug B to jug A uptill capacity
    # 5) Empty jug A 
    # 6) Empty jug B
    
    def gen_state_space(self, curr = (0, 0)):
        if (self.visited.get(curr) is not None):
            return
        self.visited[curr] = True
        (a, b) = curr
        (A, B) = (self.a, self.b)
        (_a, _b) = (A - a, B - b) # Space left
        
        # Full jugs if not full
        if (_a != 0):
            self.gen_state_space((A, b))
            self.edges.append(f"{a},{b} {A},{b}")
        if (_b != 0):
            self.gen_state_space((a, B))
            self.edges.append(f"{a},{b} {a},{B}")
        
        # Empty jugs if not empty
        if (a != 0):
            self.gen_state_space((0, b))
            self.edges.append(f"{a},{b} {0},{b}")
        
        if (b != 0):
            self.gen_state_space((a, 0))
            self.edges.append(f"{a},{b} {a},{0}")
                
        # Transfer
        if (a > 0 and _b > 0):
            self.gen_state_space((a - min(a, _b), b + min(a, _b)))
            self.edges.append(f"{a},{b} {a - min(a, _b)},{b + min(a, _b)}")
                
        if (b > 0 and _a > 0):
            self.gen_state_space((a + min(_a, b), b - min(_a, b)))
            self.edges.append(f"{a},{b} {a + min(_a, b)},{b - min(_a, b)}")
        
    def is_goal(self, node):
        a, b = map(int, node.split(","))
        return a == self.target or b == self.target

    def dfs(self, G, start="0,0"):
        stack = [start]
        parent = {start: None}
        visited = set()
        while stack:
            u = stack.pop()
            if u in visited:
                continue

            visited.add(u)

            if self.is_goal(u):
                return self._reconstruct_path(parent, u)

            for v in G.successors(u):
                if v not in visited:
                    parent[v] = u
                    stack.append(v)

        return None
    
    def bfs(self, G, start="0,0"):
        q = deque([start])
        parent = {start: None}
        visited = {start}

        while q:
            u = q.popleft()

            if self.is_goal(u):
                return self._reconstruct_path(parent, u)

            for v in G.successors(u):
                if v not in visited:
                    visited.add(v)
                    parent[v] = u
                    q.append(v)

        return None
    
    def _reconstruct_path(self, parent, target):
        path = []
        while target is not None:
            path.append(target)
            target = parent[target]
        return path[::-1]

class GraphApp:
    def __init__(self, root):
        self.root = root
        root.title("Water Jug Visualizer")

        self.search_space = None
        self.G = None

        container = ttk.Frame(root)
        container.pack(fill="both", expand=True)
        container.columnconfigure(0, weight=1)
        container.columnconfigure(1, weight=5)
        container.rowconfigure(0, weight=1)

        left = ttk.Frame(container)
        left.grid(row=0, column=0, sticky="nsew", padx=10, pady=10)

        ttk.Label(left, text="Jug 1 Capacity").pack(anchor="w")
        self.jug1_entry = ttk.Entry(left)
        self.jug1_entry.pack(fill="x")

        ttk.Label(left, text="Jug 2 Capacity").pack(anchor="w", pady=(5, 0))
        self.jug2_entry = ttk.Entry(left)
        self.jug2_entry.pack(fill="x")

        ttk.Label(left, text="Target Capacity").pack(anchor="w", pady=(5, 0))
        self.target_entry = ttk.Entry(left)
        self.target_entry.pack(fill="x")

        ttk.Button(left, text="Visualize Space", command=self.visualize_space).pack(fill="x", pady=10)

        ttk.Label(left, text="Search Type").pack(anchor="w", pady=(10, 0))
        self.search_type = tk.StringVar(value="dfs")

        ttk.Radiobutton(left, text="DFS", variable=self.search_type, value="dfs").pack(anchor="w")
        ttk.Radiobutton(left, text="BFS", variable=self.search_type, value="bfs").pack(anchor="w")

        ttk.Button(left, text="Perform Search", command=self.perform_search).pack(fill="x", pady=10)

        ttk.Label(left, text="Search Output").pack(anchor="w")
        self.output_box = tk.Text(left, height=8)
        self.output_box.pack(fill="both", expand=True)

        right = ttk.Frame(container)
        right.grid(row=0, column=1, sticky="nsew", padx=10, pady=10)
        right.rowconfigure(0, weight=1)
        right.columnconfigure(0, weight=1)

        self.fig, self.ax = plt.subplots(figsize=(7, 7))
        self.canvas = FigureCanvasTkAgg(self.fig, master=right)
        self.canvas.get_tk_widget().grid(row=0, column=0, sticky="nsew")

    def visualize_space(self):
        try:
            a = int(self.jug1_entry.get())
            b = int(self.jug2_entry.get())
            target = int(self.target_entry.get())
            if (a < 0 or b < 0 or target < 0 or target > max(a, b)):
                self.update_output("Input invalid!")
                return
        except ValueError:
            self.update_output("All inputs must be integers.")
            return
          
        self.search_space = SearchSpace(a, b, target)
        self.search_space.gen_state_space((0, 0))
        self.G = nx.DiGraph()

        for edge in self.search_space.edges:
            u, v = edge.split()
            self.G.add_edge(u, v)

        self.draw_graph()
        self.update_output("State space generated.")

    def perform_search(self):
        if not self.search_space or not self.G:
            self.update_output("Generate state space first.")
            return
        search_type = self.search_type.get()
        if search_type == "dfs":
            path = self.search_space.dfs(self.G)
        else:
            path = self.search_space.bfs(self.G)

        if not path:
            self.update_output("No solution found.")
            self.draw_graph()
            return

        # Color nodes
        node_colors = []
        for n in self.G.nodes():
            if n in path:
                node_colors.append("Orange")
            else:
                node_colors.append("LightBlue")

        # Color edges
        path_edges = set(zip(path, path[1:]))
        edge_colors = [
            "Red" if (u, v) in path_edges else "Gray"
            for u, v in self.G.edges()
        ]

        self.draw_graph(node_colors, edge_colors)
        self.update_output(" -> ".join(path))

    def draw_graph(self, node_colors="LightBlue", edge_colors="Gray"):
        self.ax.clear()
        if not self.G:
            return
        pos = nx.spring_layout(self.G, seed=42)
        nx.draw(
            self.G,
            pos,
            ax=self.ax,
            with_labels=True,
            node_size=1500,
            font_size=9,
            arrows=True,
            node_color=node_colors,
            edge_color=edge_colors,
            width=2
        )
        self.canvas.draw()

    def update_output(self, text):
        self.output_box.delete("1.0", tk.END)
        self.output_box.insert(tk.END, text)
        
if __name__ == "__main__":
    root = tk.Tk()
    root.geometry("1000x650")
    app = GraphApp(root)
    root.mainloop()