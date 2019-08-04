#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    int depth;
    Node *left, *right;
};

Node *newNode(int d)
{
    Node *temp = new Node;
    temp->data = d;
    temp->left = temp->right= NULL;
    temp->depth = 0;

    return temp;
}

int get_min_depth(Node *root)
{
    queue<Node *> q;

    root->depth = 1;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        int depth = temp->depth;
        q.pop();

        if(!temp->left && !temp->right)       //leaf reached
            return depth;

        if(temp->left)
        {
            Node *l = temp->left;
            l->depth = depth + 1;
            q.push(l);
        }

        if(temp->right)
        {
            Node *r = temp->right;
            r->depth = depth + 1;
            q.push(r);
        }
    }

    return 0;   
}

int main()
{
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 

    cout << get_min_depth(root) << endl;

    return (0);
}