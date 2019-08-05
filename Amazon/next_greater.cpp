#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

void print_greater(int *arr, int n)
{
    stack<int> st;
    st.push(arr[0]);

    for(int i=1; i<n; i++)
    {
        if(st.empty())
        {
            st.push(arr[i]);
            continue;
        }

        while(!st.empty() && arr[i] > st.top())     //arr[i] is the answer for all the elemnts that are currently in stack
        {
            cout << arr[i] << " ";
            st.pop();
        }

        st.push(arr[i]);
    }

    while(!st.empty())
    {
        cout << -1 << " ";
        st.pop();
    }
}

int main()
{
    int arr[] = {11, 13, 21, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    print_greater(arr, n);
    cout << endl;

    return (0);
}