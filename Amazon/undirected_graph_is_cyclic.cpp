#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    bool DFSUtil(int v, bool *visited, bool *stack);

public:
    Graph(int V)        //constructor
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v)      //create edge from u to v
    {
        adj[u].push_back(v);
    }

    bool isCyclic();
};

bool Graph::DFSUtil(int v, bool *visited, bool *stack)
{
    if(!visited[v])
    {
        visited[v] = true;
        stack[v] = true;

        list<int>::iterator it;
        for(it=adj[v].begin(); it!=adj[v].end(); it++)      //traverse the neighbours
        {
            if(!visited[*it] && DFSUtil(*it, visited, stack))
            {
                return true;
            }
            else if(stack[*it]== true)
                return true;
        }
    }

    stack[v] = false;
    return false;
}

bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *stack = new bool[V];

    for(int i=0; i<V; i++)      //do for every vertex
    {
        if(DFSUtil(i, visited, stack))
            return true;
    }

    return false;
}

int main()
{
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    cout << g.isCyclic() << endl;

    return (0);
}