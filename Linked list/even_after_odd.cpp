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

void print_list(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *put_even_after_odd(Node **head)
{
    Node *odd_head = NULL, *even_head=NULL;
    Node *odd_tail=NULL, *even_tail=NULL;

    Node *curr = *head;
    while(curr != NULL)
    {
        if(curr->data & 1)  //odd
        {
            if(odd_head==NULL)      //odd list is empty
            {
                odd_head = odd_tail = curr;
            }
            else
            {
                odd_tail->next = curr;
                odd_tail = curr;
            }
        }
        
        else    //even
        {
            if(even_head == NULL)       //even list is empty
            {
                even_head = even_tail = curr;
            }
            else
            {
                even_tail->next = curr;
                even_tail = curr;
            }
        }
        curr = curr->next;
    }

    if(odd_head != NULL)    //list contains atleast one odd node
    {
        *head = odd_head;
        odd_tail->next = even_head;
    }
    else        //list had only even nodes
    {
        *head = even_head;
    }

    if(even_tail != NULL)   //terminate the list
    {
        even_tail->next = NULL;
    }

    return *head;
}

int main()
{
    int n;
    Node *head = NULL;
    cin >> n;
    while(n--)
    {
        int num;
        cin >> num;
        push(&head, num);
    }
   // print_list(head);
    head = put_even_after_odd(&head);
    print_list(head);

    return (0);
}