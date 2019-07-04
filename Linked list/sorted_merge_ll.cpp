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

    if(*head == NULL)   //empty list
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

void print_list(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *sorted_merge(Node *a, Node *b)
{
    Node *res = NULL;

    if(a == NULL)
    {
        return b;
    }
    if(b == NULL)
    {
        return a;
    }

    if(a->data < b->data)
    {
        res = a;
        res->next = sorted_merge(a->next, b);
    }
    else
    {
        res = b;
        res->next = sorted_merge(a, b->next);
    }
    
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n1, n2;
        cin >> n1;
        Node *head1 = NULL;
        Node *head2 = NULL;
        while(n1--)
        {
            int num;
            cin >> num;
            push(&head1, num);
        }
        cin >> n2;
        while(n2--)
        {
            int num;
            cin >> num;
            push(&head2, num);
        }

        Node *ans = sorted_merge(head1, head2);

        print_list(ans);        
    }

    return (0);
}