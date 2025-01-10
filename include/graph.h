#pragma once

#include <vector>

struct Edge
{
    int from, to;
    int weight;

    bool operator<(const Edge &other) const 
    {
        return weight < other.weight;
    }
};

struct MST 
{
    int mst_weight;
    std::vector<Edge> mst;

    MST() : mst_weight(0), mst() {}
    MST(int weight, std::vector<Edge> edges) : mst_weight(weight), mst(std::move(edges)) {}
};

struct Graph 
{
    int num_nodes;
    std::vector<std::vector<int>> adj_matrix;
};

// @brief Performs a Depth-First Search on a graph
// @param `index` The index representing the current vertice to process
// @param `graph` The list o adjancency representing the graph
// @param `visited` Vector of bools for checking if a vertice was visited
void do_dfs(int node, std::vector<std::vector<int>>& graph, std::vector<bool>& visited);

// @brief Checks if a graph is connected
// @param `graph` A reference to a `Graph` structure
// @return True if graph is connected, otherwise false
bool is_connected(Graph& graph);

// @brief Checks if the graph is connected after the removal of an edge
// @param `graph` A reference to a `Graph` structure
// @return True if graph is connected, otherwise false
bool is_connected_after_removal(Graph& graph, int nodeX, int nodeY);

std::vector<int> find_leaf_nodes(const std::vector<Edge>& edges);

bool is_leaf(const std::vector<Edge>& edges, int node);

bool is_edge_in_mst(const Edge& edge, const std::vector<Edge>& mst);

MST add_redundancy(int n, MST& mst, const std::vector<Edge>& original_edges);
