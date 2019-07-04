#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, t;
    cin >> n;       //size of array
    vector<int> arr;

    for(int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    cin >> t;   //test cases
    int key;        //search key
    while(t--)
    {
        cin >> key;
        if(find(arr.begin(), arr.end(), key) == arr.end())  //not exist 
        {
            cout << -1 << " " <<-1 <<endl;
        }
        else
        {
            cout << lower_bound(arr.begin(), arr.end(), key) - arr.begin() << " ";
            cout << upper_bound(arr.begin(), arr.end(), key) - arr.begin() - 1 << endl;
        }
    }

    return (0);
}