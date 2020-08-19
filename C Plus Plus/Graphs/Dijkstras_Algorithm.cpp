
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
            // adj[8].push_back({7,6});
            // for(auto i:adj)
            //     cout<<i.first<<i.second;
            cout<<sizeof(adj);
        }
        void addEdge(int u, int v, int w)
        {
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        // prints shortest path from s
        void shortestPath(int s);
};
void Graph::shortestPath(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);
    vector<bool> visited(V,false);
    vector<int> par(V,-1);
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, s));
    dist[s] = 0;

    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance
        int u = pq.top().second;
        pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        for(auto i:adj[u])
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = i.first;
            int weight = i.second;

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                par[v] = u;
                pq.push(make_pair(dist[v], v));

            }
        }

    }
    // Print shortest distances stored in dist[]
    printf("Vertex  | Distance f Source | Parent \n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d \t\t%d \n", i, dist[i],par[i]);

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

    g.shortestPath(0);

    return 0;

}

