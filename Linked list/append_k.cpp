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

    if(*head == NULL)
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

Node *append_k_nodes(Node *head, int k)
{
    Node *temp = head;
    Node *t = head;

    //t will stay k places behind temp
    int i = -k;
    //when temp reaches last node, t will be at kth node from end
    while(temp->next != NULL)
    {
        if(i>=0)        //temp has moved k places from first node
        {
            t = t->next;
        }
        temp=temp->next;
        i++;
    }

    temp->next = head;  //connect last to first
    head = t->next;     //t is at kth node from end and now list starts from here
    t->next = NULL;     //end the list at kth pos from end

    return head;
}

int main()
{
    int n, k;
    Node *head = NULL;
    cin >> n;
    while(n--)
    {
        int num;
        cin >>  num;
        push(&head, num);
    }

    cin >> k;
    head = append_k_nodes(head, k);

    print_list(head);

    return (0);
}