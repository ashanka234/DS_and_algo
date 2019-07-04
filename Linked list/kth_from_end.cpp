#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **head, int d)
{
    Node *new_node = new Node;
    new_node->data = d;
    new_node->next = NULL;

    if(*head==NULL)
    {
        *head = new_node;
        return;
    }
    Node *curr = *head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

int kth_from_end(Node *head, int k)
{
    Node *temp=head, *t=head;
    int cnt=-k;

    while(temp != NULL)
    {
        if(cnt>0)
        {
            t=t->next;
        }
        temp=temp->next;
        cnt++;
    }

    return t->data;
}

int main()
{
    int k, num=0;
    Node *head = NULL;

    while(num != -1)
    {
        cin >> num;
        push(&head, num);
    }
    cin >> k;

    cout << kth_from_end(head, k) << endl;

    return (0);
}