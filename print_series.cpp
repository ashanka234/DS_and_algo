#include <iostream>
using namespace std;

int main() {

    int n1, n2, term_count=0;
    cin >> n1 >> n2;


    for(int i=1;  ;i++) 
    {
        int term = 3*i + 2;
        if (term%n2 != 0)
        {
            term_count++;
            cout << term <<endl;
        }

        if(term_count == n1)
            break;

    }

    return (0);
}