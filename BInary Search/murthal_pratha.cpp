#include<iostream>
using namespace std;

int get_root(int n)
{
    int low=0, high=10000, ans=low;
    int mid;

    while(low <= high)
    {
        mid = (high+low+1)/2;
        if(mid*(mid+1)/2 <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main() 
{
    int p, l;
    cin >> p;   //no of prathas
    cin >> l;   //no of cooks
    int *arr = new int[l];
    for(int i=0; i<l; i++)
    {
        cin >> arr[i];
    }

    
    //binary search 
    int low=0, high=1>>25, ans=high;
    int mid;

    while(low <= high)
    {
        mid = (high + low + 1) / 2;
        int cnt = 0;
        for(int i=0; i<l && cnt<p; i++)
        {
            cnt += get_root(mid / arr[i]);
        }

        if(cnt >= p)
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
        
    }
    cout << ans << endl;
    return (0);
}