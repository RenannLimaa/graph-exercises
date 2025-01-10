#include <iostream>

#include "include/tests.h"

int main() 
{
    test_is_graph_connected();
    test_is_graph_connected_after_removal();
    test_kruskal_1();
    test_kruskal_2();
    test_graph_with_redundancy_1();
    test_graph_with_redundancy_2();

    std::cout << "All tests passed" << std::endl;
}

