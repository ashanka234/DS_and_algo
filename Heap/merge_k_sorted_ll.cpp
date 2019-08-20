#include<iostream>
#include<list>
#include<iterator>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

int getMaxLen(list<int> *arr, int n)
{
    int ans = 0;

    for(int i=0; i<n; i++)
    {
        if(arr[i].size() > ans)
            ans  = arr[i].size();
    }

    return ans;
}

list<int> mergeSortedK(list<int> *arr, int n)
{
    int k = getMaxLen(arr, n);
    list<int> ans(n*k);

    priority_queue< pair<int, int> , vector< pair<int, int> >, greater< pair<int, int> > > minHeap;

    list<int>::iterator it;
    for(int i=0; i<n; i++)
    {
        //it = arr[i].begin();
        minHeap.push(make_pair(arr[i].front(), i));    //ith list number is second
        arr[i].pop_front();
    }
    
    
    for(int i=0; i<n*k; i++)
    {
        pair<int, int> root = minHeap.top();
        minHeap.pop();

        ans.push_back(root.first);
        int konsiListSeGyaHai = root.second;

        minHeap.push(make_pair(arr[konsiListSeGyaHai].front(), konsiListSeGyaHai));
        arr[konsiListSeGyaHai].pop_front();
    }

    return ans;
}

int main()
{
    int t, n, k, num;

    cin >> t;

    while(t--)
    {
        cin >> n;
        list<int> *arr = new list<int>[n];

        //input all the lists
        for(int i=0; i<n; i++)
        {
            cin >> k;       //size of each list
            
            while(k--)
            {
                cin >> num;
                arr[i].push_back(num);
            }
        }

        list<int> ans = mergeSortedK(arr, n);
        list<int>::iterator it;
        for(it=ans.begin(); it!=ans.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    return (0);
}