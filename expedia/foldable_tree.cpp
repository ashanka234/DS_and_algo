#include<iostream>
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

bool isMirror(Node *root1, Node *root2)
{
    if(root1==NULL && root2==NULL)
        return true;

    if(root1==NULL || root2==NULL)
        return false;

    
    return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}

bool isFoldable(Node *root)
{
    if(root == NULL)
        return true;

    return isMirror(root, root);
}

int main()
{
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left = newNode(5); 

    cout << isFoldable(root) << endl;

    return (0);
}