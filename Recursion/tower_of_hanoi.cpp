#include<iostream>
using namespace std;

void tower_of_hanoi(int n, char src, char dest, char aux)
{
    if(n==1 || n==0)
    {
        cout << "Moving ring " << n << " from " << src << " to " << dest << endl;
        return;
    }

    tower_of_hanoi(n-1, src, aux, dest);
    cout << "Moving ring " << n << " from " << src << " to " << dest <<endl;
    tower_of_hanoi(n-1, aux, dest, src);
}

int main()
{
    int n;
    //move from A to B, using C
    cin >> n;

    tower_of_hanoi(n, 'A', 'B', 'C');

    return (0);
}