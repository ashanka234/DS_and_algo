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

void print_top_view(Node *root)
{
    if(!root)
        return;

    queue<Node *> q;
    map<int, int> hmap;     //it stores root->data vs horizontal dist

    int hd=0;
    root->hd = hd;       //hd of root is zero

    q.push(root);

    while(!q.empty())
    {
        hd = root->hd;

        //if count is 1, means it is the first at that horizontal dist
        if(hmap.count(hd) == 0)
        {
            hmap[hd] = root->data;
        }

        if(root->left)
        {
            root->left->hd = hd-1;
            q.push(root->left);
        }
        if(root->right)
        {
            root->right->hd = hd+1;
            q.push(root->right);
        }

        q.pop();        //root nikal diya
        root = q.front();     //agle ko root banake repeat
    }   

    //ab map mei hd vs dist store ho gya hai, for those which are first for that particular hd
    //now just print the map
    map<int, int>::iterator it;
    for(it=hmap.begin(); it!= hmap.end(); it++)
    {
        cout << it->second << " ";
    }
}

int main()
{
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->right = newNode(4); 
    root->left->right->right = newNode(5); 
    root->left->right->right->right = newNode(6);

    print_top_view(root);
    cout << endl;

    return (0);
}