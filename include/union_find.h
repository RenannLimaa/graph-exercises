#pragma once

#include <vector>

struct UnionFind 
{
    std::vector<int> parent, size;
};

// @brief Initialize the `size` vector with '1'. Additionally, make each node its own parent.
// @param `uf` The UnionFind structure that will be initialized.
// @param `size` The size of the vectors.
void init_union_find(UnionFind& uf, int size);

// @brief Find the set that `element` belongs to.
// @param `uf` A reference to the  UnionFind structure.
// @param `element` The element whose parent will be searched.
int find_set(UnionFind& uf, int element);

// @brief Unite two sets.
// @param `uf` A reference to the  UnionFind structure.
// @param `a`, `b` The elements whose sets will be unified.
void union_sets(UnionFind& uf, int a, int b);
