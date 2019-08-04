#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int d)
{
    Node *temp = new Node;
    temp->data = d;
    temp->next = NULL;

    return temp;
}

void print_list(Node *head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void remove_loop(Node *head)
{
    Node *slow = head->next;
    Node *fast = head->next->next;

    while(fast && fast->next)
    {
        if(slow==fast)
            break;
        
        slow = slow->next;
        fast = fast->next->next;
    }

    if(slow==fast)      //loop was found
    {
        slow = head;        //fast is inside the loop atm
        while(slow->next != fast->next)     //both will reach one node before the loop starting node
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;      //remove the loop
    }
}

int main()
{
    Node *head = newNode(1);
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10);

    //loop
    head->next->next->next->next->next = head->next->next; 

    remove_loop(head);

    print_list(head);

    return (0);
}