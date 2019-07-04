#include<iostream>
using namespace std;

int ans = 0;

bool isSafe(int board[][11], int n, int row, int col)
{
    int i, j;

    //check left side
    for(i=0; i<col; i++)
    {
        if(board[row][i] != 0)  //left pe already queen hai ie 1
            return false;
    }

    //check left side upper diagonal
    for(i=row, j=col; i>=0 && j>=0; i--, j--)
    {
        if(board[i][j] != 0)
            return false;   //diagonal upper left pe already queen hai ie 1
    }

    //check left side lower diagonal
    for(i=row, j=col; i<n && j>=0; i++, j--)
    {
        if(board[i][j] != 0)
            return false;
    }

    //all are safe
    return true;
}

void print_soln(int board[][11], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}

bool count_n_queen(int board[][11], int n, int col)
{
    //base case - all queens placed
    if(col == n)
    {
        // cnt++;
        // cout << cnt << " ";
        // print_soln(board, n);
        // cout << endl;
        ans++;
        //cout << ans << " ";
        return true;
    }

    //for current column, try placing in all rows
    bool res = false;       //consider queen cannot be placed
    for(int i=0; i<n; i++)
    {
        //check for board[i][col]
        if( isSafe(board, n, i ,col) )
        {
            //place queen here
            board[i][col] = 1;

            res = count_n_queen(board, n, col+1) || res;   //true if any placement is possible

            //if placing here does not lead to a solution, then backtrack
            board[i][col] = 0;  //removed queen
        }
    }

    //queen not able to placed in any row then false returned
    return res;
}

int main()
{
    int n;
    cin >> n;
    
    //create NxN board of 0's
    int board[n][11];
    for(int i = 0; i < n; ++i)
    {
        for(int j=0; j<n; j++)
             board[i][j] = 0;
    }

    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<n; j++)
    //     {
    //         cout << board[i][j];
    //     }
    //     cout << endl;
    // }

    //int ans = 0;

   // cout << ans << " ";
    if(count_n_queen(board, n, 0))
    {
        cout << ans << endl;
    }

    return (0);
}