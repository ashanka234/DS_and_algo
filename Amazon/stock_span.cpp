#include<iostream>
#include<stack>
using namespace std;

void get_span(int *stock, int *span, int n)
{
    stack<int> myStack;     //stack mei indexes push honge sirf
    
    myStack.push(0);

    span[0] = 1;        //pehle wale ka humesha 1 hoga span

    for(int i=1; i<n; i++)
    {
        //jab tak current se chote element hai stack mei, toh pop krte raho
        //jab usse bada aa jayega, matlab waha tak span hai; so just subtract the indices to get the span
        while(stock[myStack.top()] <= stock[i] && !myStack.empty())
        {
            myStack.pop();
        }
        //jaha yeh loop end hua, wahi span end hai

        if(!myStack.empty())
            span[i] = i - myStack.top();
        else
            span[i] = i + 1;        //matlab yeh wala sabse bada hai ab tak 

        myStack.push(i);
    }
}

void print_arr(int *arr, int n)
{
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int stock[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(stock)/sizeof(int);
    int *span = new int[n];

    get_span(stock, span, n);

    print_arr(span, n);

    return (0);
}