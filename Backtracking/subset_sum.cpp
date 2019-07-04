#include<iostream>
using namespace std;

void print_subset(int *t, int size)
{
    for(int i=0; i<size; i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;
}

void subset_sum(int *arr, int n, int *tuplet, int t_size, int curr_sum, int i, int target_sum)
{
    if(curr_sum == target_sum)  //formed target sum
    {
        print_subset(tuplet, t_size);
        //exclude current item and try
        subset_sum(arr, n, tuplet, t_size-1, curr_sum - arr[i], i+1, target_sum);       //for other subsets
        return;
    }
    else
    {
        for(int k=i; k<n; k++)      //find nodes along breadth
        {
            tuplet[t_size] = arr[k];
            subset_sum(arr, n, tuplet, t_size+1, curr_sum+arr[k], i+1, target_sum);     //do for next node depth wise
        }
    }
    
}

int main()
{
    int n, target;
    cin >> n;
    int *input = new int[n];
    for(int i=0; i<n; i++)
    {
        cin >> input[i];
    }
    cin >> target;

    int *tuplet = new int[n];

    subset_sum(input, n, tuplet, 0, 0, 0, target);
    //delete[] tuplet;

    return (0);
}