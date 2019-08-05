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
    temp->left = temp->right = NULL;
    temp->data = d;

    return temp;
}

void create_mirror_tree(Node *root)
{
    if(!root)
        return;

    create_mirror_tree(root->left);
    create_mirror_tree(root->right);

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void print_inorder(Node *root)
{
    if(root)
    {
        print_inorder(root->left);
        cout << root->data << " ";
        print_inorder(root->right);
    }
}

bool isMirror(Node *a, Node *b)
{
    if(!a && !b)
        return true;

    if(!a || !b)
        return false;

    return (a->data == b->data)
            && isMirror(a->left, b->right)
            && isMirror(a->right, b->left);
}

int main()
{
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);  

    Node *a = newNode(1); 
    Node *b = newNode(1); 
    a->left = newNode(2); 
    a->right = newNode(3); 
    a->left->left  = newNode(4); 
    a->left->right = newNode(5); 
  
    b->left = newNode(3); 
    b->right = newNode(2); 
    b->right->left = newNode(5); 
    b->right->right = newNode(4); 

    create_mirror_tree(root);
    print_inorder(root); cout << endl;

    cout << isMirror(a, b) << endl;

    return (0);
}
