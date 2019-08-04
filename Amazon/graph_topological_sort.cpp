#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    
    void topologicalSortUtil(int v, bool *visited, stack<int> &s);

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void topologicalSort();     //only for Directed Acyclic Graph (DAG)
};

void Graph::topologicalSortUtil(int v, bool *visited, stack<int> &st)
{
    visited[v] = true;

    list<int>::iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if(!visited[*it])
        {
            topologicalSortUtil(*it, visited, st);
        }
    }

    st.push(v);
}

void Graph::topologicalSort()
{
    stack<int> st;
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            topologicalSortUtil(i, visited, st);
        }
    }

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

int main()
{
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1);

    g.topologicalSort();

    return (0);
}