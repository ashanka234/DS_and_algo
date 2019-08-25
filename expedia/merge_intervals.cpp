#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

bool myCompare(pair<int, int> a, pair<int, int> b)
{
    return (a.first < b.first);
}

void mergeIntervals(vector<pair<int, int> > &arr, int n)
{
    stack< pair<int, int> > myStack;

    std::sort(arr.begin(), arr.end(), myCompare);

    myStack.push(arr[0]);

    for(int i=1; i<n; i++)
    {
        pair<int, int> curr = myStack.top();

        if(curr.second < arr[i].first)      //not overlap
        {
            myStack.push(arr[i]);
        }

        else if(curr.second < arr[i].second)     //overlap
        {
            curr.second = arr[i].second;        //merge
            myStack.pop();
            myStack.push(curr);
        }
    }

    while(!myStack.empty())
    {
        pair<int, int> ele = myStack.top();
        myStack.pop();

        cout << ele.first << "," << ele.second << " ";
    }
    cout << endl;
}

int main()
{
    vector<pair<int, int> > arr;

    int n=4;
    int start, end;

    for(int i=0; i<n; i++)
    {
        cin >> start >> end;
        arr.push_back(make_pair(start, end));
    }

    mergeIntervals(arr, n);


    return (0);

}