#include<iostream>
#include<climits>
#include<algorithm>
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

void print_inorder(Node *root)
{
    if(root)
    {
        print_inorder(root->left);
        cout << root->data <<  " ";
        print_inorder(root->right);
    }
}

int get_max_diff_util(Node *root, int *res)
{
    if(!root)
        return INT_MAX;

    //leaf node, then return its value only
    if(root->left==NULL && root->right==NULL)
        return root->data;

    //recur for left and right subtree
    int val = min(get_max_diff_util(root->left, res), get_max_diff_util(root->right, res));

    *res = max(*res, root->data - val);         //current is ancestor, and val contains answer of subtree from recursion 

    return min(val, root->data);
}

int get_max_diff(Node *root)
{
    int res = INT_MIN;

    get_max_diff_util(root, &res);

    return res;
}

int main()
{
    Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->left->right->left = newNode(4); 
    root->left->right->right = newNode(7);
    root->right->right = newNode(14); 
    root->right->right->left = newNode(13); 

    // print_inorder(root); 
    // cout << endl;

    cout << get_max_diff(root) << endl;

    return (0);
}