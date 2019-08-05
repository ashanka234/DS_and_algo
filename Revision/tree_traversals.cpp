#include<iostream>
#include<queue>
#include<map>
#include<stack>
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

void bottomView(Node *root)
{
    if(!root)
        return;

    map<int, int> hmap;         //hd vs value of node
    queue<Node *> q;

    int hd = 0;
    root->hd = hd;

    while(!q.empty())
    {
        Node *temp = q.front();
        hd = temp->hd;
        q.pop();

        hmap[hd] = temp->data;

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
    }

    map<int, int>::iterator it;
    for(it=hmap.begin(); it!=hmap.end(); it++)
    {
        cout << it->second << " ";
    }

    cout << endl;
}

void topView(Node *root)
{
    if(!root)
        return;

    map<int, int> hmap;
    queue<Node *> q;

    int hd=0;
    root->hd = hd;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        hd = temp->hd;
        q.pop();

        if(hmap.count(hd) == 0)
        {
            hmap[hd] = root->data;
        }

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

    map<int, int>::iterator it;
    for(it=hmap.begin(); it!=hmap.end(); it++)
    {
        cout << it->second << " ";
    }
    cout << endl;
}

void leftView(Node *root, int curr_lvl, int *level)
{
    if(!root)
        return;

    if(curr_lvl > *level)
    {
        cout << root->data << " ";
        *level = curr_lvl;
    }

    leftView(root->left, curr_lvl+1, level);
    leftView(root->right, curr_lvl+1, level);
}

void rightView(Node *root, int curr_level, int *level)
{
    if(!root)
        return;

    if(curr_level > *level)
    {
        cout << root->data << " ";
        *level = curr_level;
    }

    rightView(root->right, curr_level+1, level);
    rightView(root->left, curr_level+1, level);
}

void get_min_max_hd(Node *root, int *min, int *max, int hd)
{
    if(!root)
        return;

    if(hd > *max)
        *max = hd;
    else if(hd < *min)
        *min = hd;

    get_min_max_hd(root->left, min, max, hd-1);
    get_min_max_hd(root->right, min, max, hd+1);    
}

void print_line(Node *root, int line_no, int hd)
{
    if(!root)
        return;

    if(hd==line_no)
    {
        cout << root->data << " ";
    }

    print_line(root->left, line_no, hd-1);
    print_line(root->right, line_no, hd+1);
}

void verticalOrder(Node *root)
{
    int min=0, max=0;
    get_min_max_hd(root, &min, &max, 0);

    for(int i=min; i<=max; i++)
    {
        print_line(root, i, 0);
        cout << endl;
    }
}

void levelOrder(Node *root)
{
    if(!root)
        return;

    queue<Node *> q;

    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        
        while(n)
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data <<  " ";

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);

            n--;
        }
        cout << endl;
    }  
}

void zigzagPrint(Node *root)
{
    if(!root)
        return;

    stack<Node *> current_level;
    stack<Node *> next_level;

    bool LtoR = true;
    current_level.push(root);

    while(!current_level.empty())
    {
        Node *temp = current_level.top();
        current_level.pop();

        if(temp)
        {
            cout << temp->data << " ";

            if(LtoR)
            {
                if(temp->left)
                    next_level.push(temp->left);
                if(temp->right)
                    next_level.push(temp->right);
            }
            else
            {
                if(temp->right)
                    next_level.push(temp->right);
                if(temp->left)
                    next_level.push(temp->left);
            }
        }

        if(current_level.empty())
        {
            LtoR = !LtoR;
            swap(current_level, next_level);
        }
    }
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

    return (0);
}