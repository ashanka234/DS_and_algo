#include<iostream>
#include<cmath>
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

    if(*head == NULL)
    {
        *head = temp;
        return;
    }

    temp->next = *head;
    *head = temp;
}


void add_LL(Node *num1, Node *num2)
{
    int n1 = 0;
    int n2 = 0;
    int i;

    i=0;
    while(num1)
    {
        n1 += num1->data * pow(10,i);
        num1 = num1->next;
        i++;
    }   

    i=0;
    while(num2)
    {
        n2 += num2->data * pow(10, i);
        num2 = num2->next;
        i++;
    }

    cout << n1+n2 << endl;
}

int main()
{
    int n1, n2;
    cin  >> n1;

    Node *head1=NULL, *head2=NULL;

    while(n1--)
    {
        int n;
        cin >> n;
        push(&head1, n);
    }
    //cout << 1 << endl;

    cin >> n2;

    while(n2--)
    {
        int n;
        cin >> n;
        push(&head2, n);
    }
    //cout << 2 << endl;

    add_LL(head1, head2);

    return (0);
}