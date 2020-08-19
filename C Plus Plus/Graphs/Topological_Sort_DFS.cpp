#include <bits/stdc++.h>
using namespace std;

// Class to represent a graph
class Graph
{
// No. of vertices'
    int V;

    // Pointer to an array containing adjacency listsList
    vector<vector<int>> adj;

    // A function used by topologicalSort

public:
// Constructor
    Graph(int n){
        V = n;
        adj.resize(n);
    }
     // function to add an edge to graph
    void addEdge(int v, int w);
    // prints a Topological Sort of
// the complete graph
    void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &st);
    void topologicalSort();
};

void Graph::addEdge(int v, int w)
{
// Add w to v’s list.
    adj[v].push_back(w);
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int u, vector<bool> &visited, stack<int> &st)
{
    // Mark the current node as visited.
    visited[u] = true;

    // Recur for all the vertices
// adjacent to this vertex
    for(auto v:adj[u])
        if(!visited[v])
            topologicalSortUtil(v,visited,st);

    // Push current vertex to stack
// which stores result
    st.push(u);
}

// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> st;

    // Mark all the vertices as not visited
    vector<bool> visited(V,false);

    // Call the recursive helper function
// to store Topological
    // Sort starting from all
// vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, st);

    // Print contents of stack
    while (st.empty() == false)
    {
        cout << st.top() << " ";
        st.pop();
    }
}

// Driver program to test above functions
/*  Works for only directed Acyclic Graph  */
int main()
{
    // Create a graph given in the above diagram

    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();
//    Time Complexity - > O(V+E)
//    Space Complexity -> O(V).
    return 0;
}

