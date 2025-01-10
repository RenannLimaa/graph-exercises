#include "include/union_find.h"

void init_union_find(UnionFind& uf, int size)
{ 
    uf.parent.resize(size); 
    uf.size.resize(size, 1);  

    for (int i = 0; i < size; i++)
        uf.parent[i] = i; 
}

int find_set(UnionFind& uf, int element)
{
    int root = element;
    while (root != uf.parent[root])  
        root = uf.parent[root];

    while (element != root)
    {
        int next = uf.parent[element];
        uf.parent[element] = root;
        element = next;
    }

    return root;
}

void union_sets(UnionFind& uf, int a, int b)
{
    int rootX = find_set(uf, a);
    int rootY = find_set(uf, b);

    if (rootX == rootY) return; 

    if (uf.size[rootX] < uf.size[rootY])
    {
        uf.size[rootY] += uf.size[rootX];
        uf.parent[rootX] = rootY;
    }

    else
    {
        uf.size[rootX] += uf.size[rootY];
        uf.parent[rootY] = rootX;
    }
}
