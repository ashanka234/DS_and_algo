#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **head, int d)
{
    Node *temp = new Node;
    temp->data = d;
    temp->next = NULL;
    
    if(*head == NULL)       //empty list
        *head = temp;

    else
    {
        temp->next = *head;
        *head = temp;
    }
}

void printList(Node *head)
{
    if(!head)
        return;

    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int getLength(Node *head)
{
    if(!head)
        return 0;

    int len = 0;

    while(head)
    {
        len++;
        head = head->next;
    }

    return len;
}

void swapNodes(Node **head, int n, int k)
{
    if(k > n)       //not possible, so return as is
        return;

    if(k+k-1 == n)      //kth from begining and kth from end are same, so swapping wont make a diference
        return;

    Node *x = *head;
    Node *y = *head;

    //reach x to kth from begining
    for(int i=1; i<k; i++)
    {
        x = x->next;
    }

    //reach y to kth from end, that is n-k+1 from beginning
    for(int i=1; i<n-k+1; i++)
    {
        y = y->next;
    }

    swap(x->data, y->data);
}

int main()
{
    Node *head = NULL;

    for(int i=8; i>=1; i--)
        push(&head, i);

    printList(head);

    int n = getLength(head);
    int k = 3;
    swapNodes(&head, n, k);

    printList(head);

    return (0);
}