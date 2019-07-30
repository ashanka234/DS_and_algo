#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;         //this is for DLL and tree both; left=prev, right=next
};

Node *newNode(int d)
{
    Node *temp = new Node;
    temp->data = d;
    temp->left = temp->right = NULL;

    return temp;
}

void print_list(Node *head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

void BTree_to_DLL(Node *root, Node **head)
{
    if(!root)       //base case
        return;

    static Node *prev = NULL;       //static makes it constant for all recursion calls

    //ab inorder wala order hi follow hoga => left, process root, right
    BTree_to_DLL(root->left, head);

    if(prev == NULL)        //left most leaf reached, this will be head of DLL
    {
        *head = prev;
    }
    else
    {
        root->left = prev;
        prev->right = root;     //normal DLL wala operation
    }
    
    prev = root;

    BTree_to_DLL(root->right, head);
}

void tree_to_DLL(Node *root, Node **head)
{
    if(!root)
        return;

    tree_to_DLL(root->right, head);

    root->right = *head;
    if(*head)
    {
        (*head)->left = root;
    }
    *head = root;

    tree_to_DLL(root->left, head);
}

void inorder(Node *root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root        = newNode(10); 
    root->left        = newNode(12); 
    root->right       = newNode(15); 
    root->left->left  = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36); 

    Node *head = NULL;

    //inorder(root); cout << endl;

    //BTree_to_DLL(root, &head);
    tree_to_DLL(root, &head);

    // head = newNode(1);
    // head->right = newNode(2);
    print_list(head);

    return (0);
}