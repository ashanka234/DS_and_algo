#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool myCompare(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)        //same freq, then return smaller element
    {
        return (a.first < b.first);
    }

    else        //else higher freq element will come first
    {
        return (a.second > b.second);
    }
    
}

void sortByFreq(int *arr, int n)
{
    unordered_map< int, int> freqMap;

    //store freq of all numbers
    for(int i=0; i<n; i++)
    {
        freqMap[arr[i]]++;
    }

    vector<pair<int, int> > myVector;

    //unordered_map<int, int>::iterator it;
    for(int i=0; i<n; i++)
    {
        if(freqMap[arr[i]] >= 1)
        {
            myVector.push_back(make_pair(arr[i], freqMap[arr[i]]));
            freqMap[arr[i]] = 0;        //mark as already pushed, so it wont get pushed again
        }
    }

    sort(myVector.begin(), myVector.end(), myCompare);

    for(int i=0; i<myVector.size(); i++)
    {
        //cout << myVector[i].first << " " << myVector[i].second << endl;

        for(int j=0; j<myVector[i].second; j++)
        {
            cout << myVector[i].first << " ";
        }
    }
}

int main()
{
    int a[] = { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 }; 
    int n = sizeof(a) / sizeof(a[0]); 

    sortByFreq(a, n);
    cout << endl;

    return  (0);
}