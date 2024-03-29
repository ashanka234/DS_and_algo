#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    bool DFSUtil(int v, bool *visited, int parent);

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w)      //create edge from v to w
    {
        adj[v].push_back(w);
    }

    bool isCyclic();
};

bool Graph::DFSUtil(int v, bool *visited, int parent)
{
    visited[v] = true;

    list<int>::iterator it;

    for(it = adj[v].begin(); it!=adj[v].end(); it++)
    {
        if(!visited[*it])
        {
            if(DFSUtil(*it, visited, v))        //v is the pa
                return true;
        }

        else if(*it != parent)      //if neighbout is visited but is not parent, means cycle
            return true;
    }
    return false;
}

bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            if(DFSUtil(i, visited, -1))
                return true;
        }
    }

    return false;
}

int main()
{
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4);

    Graph g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2);

    cout << g1.isCyclic() << endl;
    cout << g2.isCyclic() << endl;

    return (0);
}