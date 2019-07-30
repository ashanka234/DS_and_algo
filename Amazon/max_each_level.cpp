#include<iostream>
#include<queue>
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

void get_max(Node *root, vector<int> &v, int level)
{
    if(!root)
        return;

    if(level == v.size())       //uss level ke saare push kro
        v.push_back(root->data);
    else
    {
        if(root->data > v[level])      //new max found for that level
            v[level] = root->data;
    }

    get_max(root->left, v, level+1);
    get_max(root->right, v, level+1);
}

int main()
{
    Node *root = newNode(4);
    root->left = newNode(9);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(7);

    vector<int> ans;
    get_max(root, ans, 0);

    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return (0);
}