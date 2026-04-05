import random
import tkinter as tk
import matplotlib.pyplot as plt
import networkx as nx

root = tk.Tk()
root.title("4 Queens or 8 Queens problem")
root.geometry("400x330")

choice = tk.IntVar(root, 4)

selection_f = tk.Frame(root)
selection_f.pack()

NQueensChoice = {
    "4 Queens": 4,
    "8 Queens": 8
}
tk.Label(selection_f, text="Which problem do you wish to solve?").pack(pady=20)
for (text, value) in NQueensChoice.items():
    tk.Radiobutton(selection_f, text=text, variable=choice, 
                value=value,
                ).pack(fill='x', ipady=2)

visualize_f = tk.Frame(root)
visualize_f.pack()

def heuristic(state):
    n = len(state)
    conflicts = 0
    for i in range(n):
        for j in range(i+1, n):
            if int(state[i]) == int(state[j]):
                conflicts+=1
            if abs(int(state[i])-int(state[j])) == abs(i-j):
                conflicts+=1
    return conflicts
            
def nextStates(state):
    children = []
    for i in range(len(state)):
        for row in range(1, len(state) + 1):  
            if row != int(state[i]):           
                newState = list(state)
                newState[i] = str(row)
                children.append("".join(newState))
    return children

def pathConstruct(end, dict):
    path = []
    while end is not None:
        path.append(end)
        end = dict[end]
    return path[::-1]

def HillClimb():
    c = choice.get()
    begin = ""
    for i in range(c):
        begin += str(random.randrange(1, c+1))

    parent = {begin: None}
    print(f"beginning search with starting point: {begin}")
    curr = begin
    levels = []
    visited = set()

    while True:
        if curr in visited:
            print(f"cycle detected at: {curr}")
            return curr, pathConstruct(curr, parent), levels
        visited.add(curr)

        if heuristic(curr) == 0:
            print(curr)
            return curr, pathConstruct(curr, parent), levels

        children = nextStates(curr)
        level = []
        for s in children:
            level.append((s, heuristic(s)))
        levels.append(level)

        best = min(children, key=heuristic)
        if heuristic(best) >= heuristic(curr):
            print(f"local minima: {curr} with {heuristic(curr)} conflicts")
            return curr, pathConstruct(curr, parent), levels

        parent[best] = curr  
        curr = best          

def visualizer(goal, path, levels, N):
    plt.close('all')
    G = nx.DiGraph()
    labels = {}

    for state in path:
        G.add_node(state)
        labels[state] = f"{state}\nh={heuristic(state)}"

    for i, level in enumerate(levels):
        for (state, h) in level:
            G.add_edge(path[i], state)
            labels[state] = f"{state}\nh={h}"

    path_edges = []
    for i in range(len(path) - 1):
        path_edges.append((path[i], path[i+1]))

    pos = {path[0]: (0, 2.3)}

    for i, level in enumerate(levels):
        for j, (state, h) in enumerate(level):
            if state not in pos:
                offset = 0.1 * (-1)**j * (N // 4)
                pos[state] = (2*j - 12, -i*2 + offset)

    color_map = {}
    for node in G.nodes:
        if node == path[0]:
            color_map[node] = "gold"
        elif node == goal:
            color_map[node] = "lightgreen"
        elif node in path:
            color_map[node] = "pink"
        else:
            color_map[node] = "lightblue"
    node_colors = [color_map[node] for node in G.nodes]

    plt.figure(figsize=(13, 10))

    nx.draw_networkx_nodes(G, pos, node_color=node_colors,
                           node_size=900*(4//N + 1)//2)
    nx.draw_networkx_labels(G, pos, labels=labels, font_size=6)

    nx.draw_networkx_edges(G, pos, edgelist=list(G.edges()), width=1,
                           edge_color='gray', arrows=True, arrowsize=20)
    
    nx.draw_networkx_edges(G, pos, edgelist=path_edges, width=3,
                           edge_color='red', arrows=True, arrowsize=20)

    title_text = f"SOLUTION: {goal}" if heuristic(goal) == 0 else f"local minima: {goal}, {heuristic(goal)} conflicts"
    plt.suptitle(f"N-Queens state-space, {title_text}", fontsize=12, y=0.98)
    plt.axis('off')
    plt.tight_layout()
    print("displaying graph")
    manager = plt.get_current_fig_manager()
    manager.window.state('zoomed')
    plt.show()
    
def Solution():
    goal, path, levels = HillClimb()
    path_lbl.config(text=path_string(path))
    root.after(100, lambda: visualizer(goal, path, levels, choice.get()))
    
path_f = tk.Frame(root)
path_f.pack()

def path_string(path):
    res = ""
    for node in path:
        res += node + ' ->'
    return res.rstrip('->')

path_lbl = tk.Label(path_f, text="")
path_lbl.pack(pady=5)

visualize_btn = tk.Button(visualize_f, text="VIEW SOLUTION", command=Solution)
visualize_btn.pack(pady=20)

root.mainloop()
