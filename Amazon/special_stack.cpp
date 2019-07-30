#include<iostream>
#include<stack>
using namespace std;

class myStack
{
    stack<int> main;
    stack<int> aux;     //this will store min elements for current element in main(for current state)

public:

    void push(int x)
    {
        if(main.empty())
        {
            main.push(x);
            aux.push(x);
            return;
        }

        main.push(x);
        int t = aux.top();
        
        if(x<t)
            aux.push(x);
        else
            aux.push(t);
    }

    int pop()
    {
        int x = main.top();
        main.pop();
        aux.pop();

        return x;
    }

    int get_min()
    {
        int x = aux.top();
        
        return x;
    }
};

int main()
{
    myStack ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    cout << ms.pop() << endl;
    cout << ms.get_min() << endl;
    cout << ms.pop() << endl;
    cout << ms.get_min() << endl;

    return (0);
}