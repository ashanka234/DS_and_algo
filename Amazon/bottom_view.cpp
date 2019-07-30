#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct Node
{
    int data;
    int hd;
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

void print_bottom_view(Node *root)
{
    if(!root)
        return;

    map<int, int> hmap;
    queue<Node *> q;

    int hd = 0;
    root->hd = hd;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        hd = temp->hd;

        hmap[hd] = temp->data;      //map will store hd vs data; matlab uss hd pe jo wale nodes hai

        if(temp->left)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
        if(temp->right)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }

    map<int,int>::iterator it;
    for(it=hmap.begin(); it!=hmap.end(); it++)
    {
        cout << it->second << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = newNode(20); 
    root->left = newNode(8); 
    root->right = newNode(22); 
    root->left->left = newNode(5); 
    root->left->right = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(25); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14);

    print_bottom_view(root);

    return (0);
}