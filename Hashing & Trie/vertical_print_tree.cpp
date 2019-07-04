#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node (int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};


Node *buildTree()
{
    int d;
    cin >> d;

    if(d == -1)
    {
        return NULL;
    }

    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void getVerticalOrder(Node *root, int hd, map<int, vector<int> > &m)
{
    if(root == NULL)
    {
        return;

    }

    m[hd].push_back(root->data);
    getVerticalOrder(root->left, hd-1, m);
    getVerticalOrder(root->right, hd+1, m);
}

void printVerticalOrder(Node *root)
{
    map< int, vector<int> > m;
    int hd = 0;
    getVerticalOrder(root,hd,m);

    map< int, vector<int> > :: iterator it;
    for(it = m.begin(); it != m.end();it++)
    {
        for(int i=0; i<it->second.size(); i++)
        {
            cout << it->second[i]  << " ";
        }
        cout << endl;
    }
}

int main()
{
    Node *root = buildTree();
    printVerticalOrder(root);

    return (0);
}