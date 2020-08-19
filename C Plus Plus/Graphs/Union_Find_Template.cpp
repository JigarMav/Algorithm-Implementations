#include <bits/stdc++.h>
using namespace std;
class UnionFind{
    private:
    vector<int> rank;
    vector<int> parent;
    public:
    UnionFind(int n)
    {
        rank.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i] = i;
    }

    int find(int node)
    {
        while(parent[node]!=node)
        {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;

        // OR
        /*
        if(parent[node]==node)
            return node;
        return parent[node] = find(parent[node]);
        */
    }
    // union is a key-word in cpp
    void union_operation(int node1, int node2)
    {
        int par1 = find(node1);
        int par2 = find(node2);

        if(par1==par2)
            return ;
        if(rank[par1]>rank[par2])
        {
            parent[par2] = par1;
        }
        else if(rank[par1]<rank[par2])
            parent[par1] = par2;
        else
        {
            parent[par1] = par2;
            rank[par2]++;
        }
    }
}
int main() {
    // n for no of vertices
    int n;
    // take matrix input
    UnionFind *uf = new UnionFind(n);
    // uf->union_operation(i,j)
    // uf->find(i)

    /*
    Time  - > O(Log*N)
    Space - > O(N)
    */
    return 0;
}
}
