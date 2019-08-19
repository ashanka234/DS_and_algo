#include<iostream>
#include<stack>
using namespace std;

/*
class MinStack
{
    stack<int> st;
    int minEle;

public:

    void push(int d)
    {
        if(st.empty())
        {
            st.push(d);
            minEle = d;
        }
        else
        {
            if(d < minEle)
            {
                st.push(2*d - minEle);
                minEle = d;
            }
            else
            {
                st.push(d);
            }
        } 
    }

    int pop()
    {
        int x = st.top();
        st.pop();

        if(x < minEle)
        {
            minEle = 2*minEle - x;
        }

        return x;
    }

    int get_min()
    {
        return minEle;
    }
}; */



class MinStack
{
    stack<int> st;
    stack<int> min;

public:
    void push(int d)
    {
        if(st.empty())
        {
            st.push(d);
            min.push(d);
            return;
        }

        if(d < min.top())
        {
            st.push(d);
            min.push(d);
        }
        else
        {
            int x = min.top();
            st.push(d);
            min.push(x);
        }
    }

    int pop()
    {
       min.pop();

       int x = st.top();
       st.pop();

       return x;
    }

    int get_min()
    {
        return min.top();
    }
};

int main()
{
    int t;
    MinStack myStack;
    cin >> t;

    while(t--)
    {
        int n, ch;
        cin >> n;

        for(int i=0; i<n; i++)
        {
            //int ch;
            cin >> ch;

            if(ch == 1)
            {
                int d;
                cin >> d;
                myStack.push(d);
            }

            else if(ch == 2)
            {
                cout << myStack.pop() << " ";
            }

            else
            {
                cout << myStack.get_min() << " ";
            }
            cout << endl;
            
        }
    }

    return (0);
}