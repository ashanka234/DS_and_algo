#include<iostream>
using namespace std;

struct Node 
{
    int data;
    Node *next;
};

void push(Node **head, int d)
{
    if(*head == NULL)       //list is empty
    {
        Node *new_node = new Node;
        new_node->data = d;
        new_node->next = NULL;
        *head = new_node;
    }

    else
    {
        Node *new_node = new Node;
        new_node->data = d;
        Node *curr = *head;
        while(curr->next!=NULL)
        {
            curr = curr->next;
        }
        curr->next = new_node;
        new_node->next = NULL;
    }
}

void print_list(Node *head)
{
    while(head!=NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *reverse_k(Node *head, int k)
{
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    int cnt = 0;

    //reverse first k window
    while(curr!=NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    //curr ,next is now at k+1 node
    //prev is the first node of reversed list in first k window
    if(next != NULL)
    {
        head->next = reverse_k(next, k);        //call for next k size window, next is now the first node of the next window
    }

    return prev;
}

int main()
{
    Node *head = NULL;
    // push(&head, 1);
    // push(&head, 2);
    // push(&head, 3);
    // print_list(head);
    int n, k;
    cin >> n >> k;

    while(n--)
    {
        int num;
        cin >> num;
        push(&head, num);
    }

    head = reverse_k(head, k);
    print_list(head);

    return (0);
}