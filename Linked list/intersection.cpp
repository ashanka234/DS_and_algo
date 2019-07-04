#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int get_length(Node *h)
{
    int cnt=0;
    while(h)
    {
        cnt++;
        h=h->next;
    }

    returen cnt;
}

int get_intersection(Node *head1, Node *head2)
{
    int length_1 = get_length(head1);
    int length_2 = get_length(head2);
    int d;

    if(lenght_1 > length_2)
    {
        d = length_1 - length_2;
    }
    else
    {
        d = length_2 - length_1;
    }

    int i;
    Node *curr1=head1, *curr2=head2;

    for(i=0; i<d; i++)
    {
        if(curr1 == NULL)
        {
            return -1;
        }
        curr1 = curr1->next;
    }

    while(curr1 && curr2)
    {
        if(curr1 == curr2)
        {
            return curr1->data;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }

    return -1;  //no interection
}

int main()
{
    
}