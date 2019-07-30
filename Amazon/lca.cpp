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
    temp->left = temp->right = NULL;
    temp->data = d;

    return temp;
}

Node *find_LCA(Node *root, int n1, int n2)
{
    if(!root)
        return NULL;

    if(root->data == n1 || root->data == n2)        //agar root hi dono mei se koi ek hai, toh wahi dusre ka ancestor hai
        return root;            //and wahi hai LCS

    Node *left_lca = find_LCA(root->left, n1, n2);
    Node *right_lca = find_LCA(root->right, n1, n2);

    if(left_lca && right_lca)
        return root;

    if(left_lca)
        return left_lca;
    else
        return right_lca;
}

int main()
{
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 

    Node *ans = find_LCA(root, 4, 5);
    cout << ans->data << endl;

    return (0);
}