#include<iostream>
#include<list>
using namespace std;

//white=unprocessed, gray=in process, black=already processed
enum Color {WHITE, GRAY, BLACK};

class Graph
{
    int V;
    list<int> *adjList;

    bool DFSUtil(int v, int color[]);

public:
    Graph(int v)        //cosntructor
    {
        V = v;
        adjList = new list<int>[v];
    }

    void addEdge(int v, int w)
    {
        adjList[v].push_back(w);
    }

    bool isCyclic();
};

bool Graph::DFSUtil(int u, int color[])
{
    color[u] = GRAY;            //Gray means vertex is  being processed during DFS ie function is in call stack

    list<int>::iterator it;
    for(it=adjList[u].begin(); it!=adjList[u].end(); ++it)
    {
        int v = *it;        //neighour

        if(color[v]==GRAY)
            return true;

        if(color[v]==WHITE && DFSUtil(v, color))
            return true;
    }
    color[u] = BLACK;

    return false;
}

bool Graph::isCyclic()
{
    int *color = new int[V];
    for(int i=0; i<V; i++)
        color[i] = WHITE;

    for(int i=0; i<V; i++)
    {
        if(color[i]==WHITE)
        {
            if(DFSUtil(i, color))
                return true;
        }
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