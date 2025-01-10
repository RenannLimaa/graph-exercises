#include <algorithm>
#include <climits>
#include <map>
#include <unordered_map>

#include "include/graph.h"
void do_dfs(int node, std::vector<std::vector<int>>& graph, std::vector<bool>& visited)
{
    visited[node] = true;

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
            do_dfs(neighbor, graph, visited);
    }
}

bool is_connected(Graph& graph)
{
    std::vector<bool> visited(graph.num_nodes, false);
    do_dfs(0, graph.adj_matrix, visited);

    for (bool v : visited)
    {
        if (!v) return false;
    }
    return true;
}

bool is_connected_after_removal(Graph& graph, int nodeX, int nodeY)
{
    auto& adjX = graph.adj_matrix[nodeX];
    auto& adjY = graph.adj_matrix[nodeY];
    
    adjX.erase(std::find(adjX.begin(), adjX.end(), nodeY));
    adjY.erase(std::find(adjY.begin(), adjY.end(), nodeX));

    bool result = is_connected(graph);
    adjX.push_back(nodeY);
    adjY.push_back(nodeX);

    return result;
}

bool is_edge_in_mst(const Edge& edge, const std::vector<Edge>& mst) 
{
    for (const auto& e : mst) 
    {
        if ((e.from == edge.from && e.to == edge.to) || (e.from == edge.to && e.to == edge.from)) 
        {
            return true;
        }
    }
    return false;
}
std::vector<int> find_leaf_nodes(const std::vector<Edge>& edges)
{
    std::unordered_map<int, int> degree_count;
    
    for (const auto& edge : edges) 
    {
        degree_count[edge.from]++;
        degree_count[edge.to]++;
    }

    std::vector<int> leafNodes;
    for (const auto& entry : degree_count) 
    {
        if (entry.second == 1)
            leafNodes.push_back(entry.first);
    }

    return leafNodes;
}

MST add_redundancy(int n, MST& mst, const std::vector<Edge>& original_edges) 
{
    std::vector<Edge> redundant_mst = mst.mst;

    std::map<int, std::vector<int>> neighbors;
    for (const auto& edge : original_edges) 
    {
        neighbors[edge.from].push_back(edge.to);
        neighbors[edge.to].push_back(edge.from);
    }

    std::vector<int> leaf_nodes = find_leaf_nodes(mst.mst);

    for (int leaf : leaf_nodes) 
    {
        Edge min_weight_edge = {leaf, -1, INT_MAX};

        for (int neighbor : neighbors[leaf]) 
        {
            for (const auto& candidate_edge : original_edges) 
            {
                if ((candidate_edge.from == leaf && candidate_edge.to == neighbor) || 
                    (candidate_edge.from == neighbor && candidate_edge.to == leaf)) 
                {
                    if (!is_edge_in_mst(candidate_edge, redundant_mst) && candidate_edge.weight < min_weight_edge.weight) 
                    {
                        min_weight_edge = candidate_edge;
                    }
                }
            }
        }

        if (min_weight_edge.to != -1 && !is_edge_in_mst(min_weight_edge, redundant_mst)) 
            redundant_mst.push_back(min_weight_edge);
    }

    int total_weight = 0;
    for (const auto& edge : redundant_mst) {
        total_weight += edge.weight;
    }
    return {total_weight, redundant_mst};
}
