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

void leftView(Node *root, int curr_lvl, int *lvl)
{
    if(!root)
        return;

    if(curr_lvl > (*lvl))      //matlab curr level agle level pe chala gya hai, so it is the first node of that level
    {
        cout << root->data << " ";
        *lvl = curr_lvl;     //moved to next level
    }

    leftView(root->left, curr_lvl+1, lvl);
    leftView(root->right, curr_lvl+1, lvl);
}

int main()
{
    Node* root = newNode(12); 
    root->left = newNode(10); 
    root->right = newNode(30); 
    root->right->left = newNode(25); 
    root->right->right = newNode(40);

    int level = 0;
    leftView(root, 1, &level);

    return (0);
}