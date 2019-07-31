#include<iostream>
#include<algorithm>
using namespace std;

int max_sum(int *arr, int n)
{
    int excl = 0;
    int incl = arr[0];

    for(int i=1; i<n; i++)
    {
        int old_incl = incl;
        incl = excl + arr[i];       //agar current include hai, toh pichla exclude hua hoga cuz no adjacent allowed
        excl = max(excl, old_incl);     //agar curr bhi exclude hao, toh pichle state ke incl ya excl jo zyada tha woh hi current state ka answer hai
    }

    return max(incl, excl);
}

int main()
{
    int arr[] = {5,  5, 10, 40, 50, 35};
    int n = sizeof(arr)/sizeof(int);

    cout << max_sum(arr, n) << endl;

    return (0);
}