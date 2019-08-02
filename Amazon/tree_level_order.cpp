#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int d)
{
    Node *temp = new Node;
    temp->data = d;
    temp->left = temp->right = NULL;

    return temp;
}

void print_level_order(Node *root)
{
    if(!root)
        return;

    queue<Node *> q;

    q.push(root);

    while(!q.empty())
    {
        int n = q.size();       //no. of nodes at current level
        
        while(n > 0)
        {
            Node *curr = q.front();
            cout << curr->data << " ";
            q.pop();
            //cout << endl;

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
            
            n--;
        }
        cout << endl;
    }
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    print_level_order(root);

    return (0);
}