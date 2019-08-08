#include<iostream>
#include<queue>
#include<list>
#include<stack>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    void DFSUtil(int v, bool *visited);
    void topologicalSortUtil(int v, bool *visited, stack<int> &st);

    bool isCyclicUtil(int v, bool *visited, int parent);

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void BFS(int s);

    void DFS(int v);

    void topologicalSort();

    bool isCyclic();
};

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(!q.empty())
    {
        int temp = q.front();
        cout << temp << " ";
        q.pop();

        list<int>::iterator it;
        for(it=adj[temp].begin(); it!=adj[temp].end(); it++)
        {
            if(!visited[*it])
            {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
    cout << endl;
}

void Graph::DFSUtil(int v, bool *visited)
{
    cout << v << " ";
    visited[v] = true;

    list<int>::iterator it;

    for(it=adj[v].begin(); it!=adj[v].end(); it++)
    {
        if(!visited[*it])
        {
            DFSUtil(*it, visited);
        }
    }
}

void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

    DFSUtil(v, visited);
}


void Graph::topologicalSortUtil(int v, bool *visited, stack<int> &st)
{
    visited[v] = true;
    
    list<int>::iterator it;
    for(it=edj[v].begin(); it!=adj[v].end(); it++)
    {
        if(!visited(*it))
        {
            topologicalSortUtil(*it, visited, st);
        }
    }
    st.push(v);
}

void Graph::topologicalSort()
{
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    stack<int> st;

    for(int i=0; i<V; i++)
    {
        if(!visited[i])
            topologicalSortUtil(i, visited, st);
    }

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

void Graph::isCyclicUtil(int v, bool *visited, int parent)
{
    visited[v] = true;
    list<int>::iterator it;

    for(it = adj[v].begin(); it!= adj[v].end(); it++)
    {
        if(!visited[*it])
        {
            if(isCyclicUtil(*it, visited, v))
                return true;
        }
        else if(*it != parent)
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
            return isCyclicUtil(i, visited, -1);
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

    //g.BFS(2);
    g.DFS(2); cout << endl;

    return (0);
}