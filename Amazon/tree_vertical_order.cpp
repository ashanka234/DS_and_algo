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

void get_min_max_hd(Node *root, int *min, int *max, int hd)
{
    if(!root)
        return;

    if(hd < *min)
        *min = hd;
    else if(hd > *max)
        *max = hd;

    get_min_max_hd(root->left, min, max, hd-1);
    get_min_max_hd(root->right, min, max, hd+1);
}

void print_line(Node *root, int hd, int line)
{
    if(!root)
        return;

    if(hd == line)
    {
        cout << root->data << " ";
    }

    print_line(root->left, hd-1, line);
    print_line(root->right, hd+1, line);
}

void print_vertical_order(Node *root)
{
    if(!root)
        return;

    int min=0, max=0;
    get_min_max_hd(root, &min, &max, 0);

    for(int line=min; line<=max; line++)
    {
        print_line(root, 0, line);
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
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9);

    print_vertical_order(root);

    return (0);
}