#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

// Represents an edge in the graph.
struct Edge {
    int src, dest;
    int weight;

    // For sorting edges by weight.
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Represents a graph using a list of vertices and edges.
struct Graph {
    int V;
    std::vector<Edge> edges;
};

void kruskalMST(Graph& g) {
    // 1. Sort all edges in non-decreasing order of their weight.
    std::sort(g.edges.begin(), g.edges.end());
    
    std::cout << "\n--- Kruskal's Algorithm Execution ---\n";
    std::cout << "Edges sorted by weight:\n";
    for(const auto& edge : g.edges) {
        std::cout << "Edge " << edge.src << "-" << edge.dest << " Weight: " << edge.weight << std::endl;
    }

    // TODO: Implement cycle detection and MST construction.
}

int main() {
    std::cout << "===== Kruskal's Algorithm - Sorting Step =====\n";
    
    Graph graph;
    graph.V = 4;
    graph.edges.push_back({0, 1, 10});
    graph.edges.push_back({1, 2, 2}); // low weight
    graph.edges.push_back({0, 2, 6});
    graph.edges.push_back({2, 3, 4});
    graph.edges.push_back({0, 3, 5});

    kruskalMST(graph);
    
    return 0;
}