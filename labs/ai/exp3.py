
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
        
    
    def dfs(self, curr = (0, 0)):
        if (self.dfs_visited.get(curr) is not None):
            return False
        (a, b) = curr
        self.dfs_visited[curr] = True
        self.dfs_colors[f"{a},{b}"] = "Green"
        if (a == self.target or b == self.target):
            self.dfs_colors[f"{a},{b}"] = "Orange"
            return True
        (A, B) = (self.a, self.b)
        (_a, _b) = (A - a, B - b) # Space left
        
        # Full jugs if not full
        if (_a != 0):
            res = self.dfs((A, b))
            self.dfs_edges.append(f"{a},{b} {A},{b}")
            if res: 
                return True
        if (_b != 0):
            res = self.dfs((a, B))
            self.dfs_edges.append(f"{a},{b} {a},{B}")
            if res: 
                return True

        # Empty jugs if not empty
        if (a != 0):
            res = self.dfs((0, b))
            self.dfs_edges.append(f"{a},{b} {0},{b}")
            if res: 
                return True

        if (b != 0):
            res = self.dfs((a, 0))
            self.dfs_edges.append(f"{a},{b} {a},{0}")
            if res: 
                return True

        # Transfer
        if (a > 0 and _b > 0):
            res = self.dfs((a - min(a, _b), b + min(a, _b)))
            self.dfs_edges.append(f"{a},{b} {a - min(a, _b)},{b + min(a, _b)}")
            if res: 
                return True

        if (b > 0 and _a > 0):
            res = self.dfs((a + min(_a, b), b - min(_a, b)))
            self.dfs_edges.append(f"{a},{b} {a + min(_a, b)},{b - min(_a, b)}")
            if res: 
                return True

        return False
    
    def bfs(self, curr = (0, 0)):
        q = deque([curr])

        while len(q):
            curr = q.popleft()   # pop front
            if (self.bfs_visited.get(curr) is None):
                (a, b) = curr
                self.bfs_visited[curr] = True
                self.bfs_colors[f"{a},{b}"] = "Green"
                if (a == self.target or b == self.target):
                    self.bfs_colors[f"{a},{b}"] = "Orange"
                    break
                (A, B) = (self.a, self.b)
                (_a, _b) = (A - a, B - b) # Space left

                # Full jugs if not full
                if (_a != 0):
                    q.append((A, b))
                    self.bfs_edges.append(f"{a},{b} {A},{b}")

                if (_b != 0):
                    q.append((a, B))
                    self.bfs_edges.append(f"{a},{b} {a},{B}")
                
                # Empty jugs if not empty
                if (a != 0):
                    q.append((0, b))
                    self.bfs_edges.append(f"{a},{b} {0},{b}")

                if (b != 0):
                    q.append((a, 0))
                    self.bfs_edges.append(f"{a},{b} {a},{0}")

                # Transfer
                if (a > 0 and _b > 0):
                    q.append((a - min(a, _b), b + min(a, _b)))
                    self.bfs_edges.append(f"{a},{b} {a - min(a, _b)},{b + min(a, _b)}")

                if (b > 0 and _a > 0):
                    q.append((a + min(_a, b), b - min(_a, b)))
                    self.bfs_edges.append(f"{a},{b} {a + min(_a, b)},{b - min(_a, b)}")


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
        if not self.search_space:
            self.update_output("Generate state space first.")
            return
        
        self.search_space.dfs_visited = {}
        self.search_space.dfs_edges = []
        self.search_space.dfs_colors = {}
        
        self.search_space.bfs_visited = {}
        self.search_space.bfs_edges = []
        self.search_space.bfs_colors = {}
        search_type = self.search_type.get()
        colors = []
        if search_type == "dfs":
            self.search_space.dfs()
            self.update_output("\n".join(self.search_space.dfs_edges))
            colors = [self.search_space.dfs_colors[n] if n in self.search_space.dfs_colors else "Blue" for n in self.G.nodes()]
        else:
            self.search_space.bfs()
            self.update_output("\n".join(self.search_space.bfs_edges))
            colors = [self.search_space.bfs_colors[n] if n in self.search_space.bfs_colors else "Blue" for n in self.G.nodes()]
            
        self.draw_graph(colors)

    def draw_graph(self, colors = "Blue"):
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
            node_color=colors
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