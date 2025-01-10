#include <algorithm>

#include "include/kruskal.h"
#include "include/union_find.h"

MST do_kruskal(std::vector<Edge> edges, int num_nodes)
{
    UnionFind uf;
    init_union_find(uf, num_nodes);

    MST result;

    std::vector<Edge> sorted_edges = edges;

    sort(sorted_edges.begin(), sorted_edges.end());

    for (const auto &edge: sorted_edges)
    {
        int u = edge.from;
        int v = edge.to;

        if (find_set(uf, u) == find_set(uf, v))
            continue;
        
        result.mst_weight += edge.weight;
        result.mst.push_back(edge);
        union_sets(uf, u, v);
        
    }

    return result;
}
