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
    Node *new_node = new Node;
    new_node->data = d;
    new_node->left = new_node->right = NULL;

    return new_node;
}

void print_arr(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_paths(Node *root, int *path_array, int path_len)
{
    if(root == NULL)
    {
        return;
    }

    path_array[path_len] = root->data;
    path_len++;

    //check for leaf
    if(root->left==NULL && root->right==NULL)   //end of curr path cuz leaf reached
    {
        print_array(path_array, path_len);
    }
    else    //try remaining subtrees
    {
        print_paths(root->left, path_array, path_len);
        print_paths(root->right, path_array, path_len);
    }
}

int main()
{
    Node *root = newNode(10);  
    root->left = newNode(8);  
    root->right = newNode(2);  
    root->left->left = newNode(3);  
    root->left->right = newNode(5);  
    root->right->left = newNode(2);

    int path[100];
    print_paths(root);

    return (0);
}