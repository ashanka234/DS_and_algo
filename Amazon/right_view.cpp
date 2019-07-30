#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int d)
{
    Node *temp = new Node;
    temp->data = d;
    temp->left = temp->right = NULL;

    return temp;
}

void right_view(Node *root, int curr_lvl, int *lvl)
{
    if(!root)
        return;

    if(curr_lvl > *lvl)
    {
        cout << root->data << " ";
        *lvl = curr_lvl;
    }

    right_view(root->right, curr_lvl+1, lvl);
    right_view(root->left, curr_lvl+1, lvl);
}

int main()
{
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
  
    int level = 0;
    right_view(root, 1, &level);

    return (0);
}
