#include <cassert>
#include <iostream>

#include "include/tests.h"
#include "include/graph.h"
#include "include/kruskal.h"

void test_is_graph_connected()
{
    Graph graph;
    graph.num_nodes = 5;

    graph.adj_matrix.resize(graph.num_nodes);

    graph.adj_matrix[0] = {1, 3};
    graph.adj_matrix[1] = {0, 2, 4};
    graph.adj_matrix[2] = {1};
    graph.adj_matrix[3] = {0, 4};
    graph.adj_matrix[4] = {1, 3};

    assert(is_connected(graph) == true);
}

void test_is_graph_connected_after_removal()
{
    Graph graph;
    graph.num_nodes = 5;

    graph.adj_matrix.resize(graph.num_nodes);

    graph.adj_matrix[0] = {1, 3};
    graph.adj_matrix[1] = {0, 2, 4};
    graph.adj_matrix[2] = {1};
    graph.adj_matrix[3] = {0, 4};
    graph.adj_matrix[4] = {1, 3};

    assert(is_connected_after_removal(graph, 1, 2) == false);
    assert(is_connected_after_removal(graph, 0, 3) == true);
}


void test_kruskal_1()
{
    std::vector<Edge> edges = {
        {0, 1, 3},
        {0, 2, 1},
        {1, 2, 4},
        {1, 3, 6},
        {2, 3, 5},
        {2, 4, 2},
        {3, 4, 7},
        {3, 5, 8},
        {4, 6, 3},
        {5, 6, 4},
    };

    int num_nodes = 7;

    MST mst = do_kruskal(edges, num_nodes);

    assert(mst.mst_weight == 18);

    std::cout << "MST weight: " << mst.mst_weight << std::endl;
    std::cout << "Edges in MST:" << std::endl;
    for (const auto& edge : mst.mst) 
    {
        std::cout << edge.from << " - " << edge.to << " - " << edge.weight << std::endl;
    }

    std::cout << std::endl;
}

void test_kruskal_2()
{
     std::vector<Edge> edges = {
         {0, 1, 4},
         {0, 2, 2},
         {1, 3, 5},
         {1, 4, 10},
         {2, 4, 3},
         {2, 5, 8},
         {3, 6, 6},
         {4, 7, 7},
         {5, 8, 1},
         {6, 9, 9},
         {7, 9, 4},
         {8, 9, 2}
     };

    int num_nodes = 10;

    MST mst = do_kruskal(edges, num_nodes);

    assert(mst.mst_weight == 34);

    std::cout << "MST weight: " << mst.mst_weight << std::endl;
    std::cout << "Edges in MST:" << std::endl;
    for (const auto& edge : mst.mst) 
    {
        std::cout << edge.from << " - " << edge.to << " - " << edge.weight << std::endl;
    }
    std::cout << std::endl;
}

void test_graph_with_redundancy_1()
{
    std::vector<Edge> edges = {
        {0, 1, 3},
        {0, 2, 1},
        {1, 2, 4},
        {1, 3, 6},
        {2, 3, 5},
        {2, 4, 2},
        {3, 4, 7},
        {3, 5, 8},
        {4, 6, 3},
        {5, 6, 4}
    };

    int n = 7;

    MST mst = do_kruskal(edges, n);

    MST redundant_mst = add_redundancy(n, mst, edges);
    std::cout << "Subgraph with redudancy:\n";
    for (const auto& edge : redundant_mst.mst) {
        std::cout << edge.from << " - " << edge.to << " : " << edge.weight << std::endl;
    }

    std::cout << "\nNew weight of subgraph: " << redundant_mst.mst_weight << std::endl;
    std::cout << std::endl;
}

void test_graph_with_redundancy_2()
{
     std::vector<Edge> edges = {
         {0, 1, 4},  // A -> B
         {0, 2, 2},  // A -> C
         {1, 3, 5},  // B -> D
         {1, 4, 10}, // B -> E
         {2, 4, 3},  // C -> E
         {2, 5, 8},  // C -> F
         {3, 6, 6},  // D -> G
         {4, 7, 7},  // E -> H
         {5, 8, 1},  // F -> I
         {6, 9, 9},  // G -> J
         {7, 9, 4},  // H -> J
         {8, 9, 2},  // I -> J
     };

    int n = 10; 

    MST mst = do_kruskal(edges, n);

    MST redundant_mst = add_redundancy(n, mst, edges);
    std::cout << "Subgraph with redudancy:\n";
    for (const auto& edge : redundant_mst.mst) {
        std::cout << edge.from << " - " << edge.to << " : " << edge.weight << std::endl;
    }

    std::cout << "\nNew weight of subgraph: " << redundant_mst.mst_weight << std::endl;
    std::cout << std::endl;
}
