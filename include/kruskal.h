#pragma once

#include <vector>

#include "graph.h"

// @brief Kruskal algorithm to find Minimum Spanning Tree (MST)
// @param `edges` Edges in the graph
// @param `num_nodes` The number of nodes in the graph
// @brief Structure that represents an edge of a graph.
MST do_kruskal(std::vector<Edge> edges, int num_nodes);
