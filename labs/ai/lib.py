import networkx as nx


class Search:
    # hashify for when the node is not hashable (cause it is mutable). So we provide a custom hashify function
    def __init__(self, G):
        self.G = G

    def hashify(self, node):
        return node

    def info(self, node, metadata):
        for k, v in metadata.items():
            self.G.nodes[self.hashify(node)][k] = v

    def track(self, node):
        if node not in self.G.nodes:
            self.G.add_node(self.hashify(node))

    def link(self, parent, child):
        # if the nodes are not created, they shall be created!
        self.G.add_edge(self.hashify(parent), self.hashify(child))

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
