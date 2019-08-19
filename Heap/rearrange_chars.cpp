#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct Key
{
    int freq;
    char ch;

    bool operator<(const Key &k) const
    {
        return freq < k.freq;
    }
};

void rearrange_string(string str)
{
    int n = str.length();

    int count[26] = {0};

    for(int i=0; i<n; i++)
    {
        count[str[i] - 'a']++;
    }

    priority_queue< Key > pq;

    for(char c='a'; c<='z'; c++)
    {
        if(count[c-'a'] > 0)
        {
            pq.push( Key { count[c-'a'], c} );
        }
    }

    str = "";

    Key prev {-1, '#'};

    while(!pq.empty())
    {
        Key k = pq.top();
        pq.pop();

        str = str + k.ch;

        if(prev.freq > 0)
        {
            pq.push(prev);
        }

        (k.freq)--;
        prev = k;
    }

    cout << str << endl;
}

int main()
{
    int t;
    string str;

    cin >> t;

    while(t--)
    {
        cin >> str;
        
        rearrange_string(str);
        //cout << str << endl;
    }

    return (0);
}