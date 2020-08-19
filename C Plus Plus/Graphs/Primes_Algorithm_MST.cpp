
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
# define INF 0x3f3f3f3f

// Class to represent a graph
class Graph
{
    int V;
    vector<vector<pair<int,int>>> adj;

    public:
        Graph(int n)
        {
            V = n;
            adj.resize(n);

        }
        void addEdge(int u, int v, int w)
        {
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        // prints shortest path from s
        void primMST();
};

// Prints shortest paths from src to all other vertices
void Graph::primMST()
{
    priority_queue< pii, vector <pii> , greater<pii> > pq;

    int src = 0; // Taking vertex 0 as source

    // Create a vector for keys and initialize all
    // keys as infinite (INF)
    vector<int> key(V, INF);
    // To store parent array which in turn store MST
    vector<int> parent(V, -1);

    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);

    // Insert source itself in priority queue and initialize
    // its key as 0.
    pq.push(make_pair(0, src));
    key[src] = 0;

    /* Looping till priority queue becomes empty */
    while (!pq.empty())
    {

        int u = pq.top().second;
        pq.pop();
        if(inMST[u]) continue;
        inMST[u] = true;  // Include vertex in MST

        // 'i' is used to get all adjacent vertices of a vertex
        for(auto i:adj[u])
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = i.first;
            int weight = i.second;

            //  If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

int main()
{
    int V = 9;
    Graph g(V);

     // making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.primMST();

//     Time - O(E LogV)

    return 0;

}

