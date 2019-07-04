#include<iostream>
using namespace std;
#define MAX 1000

void print_soln(int arr[][MAX], int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(char maze[][MAX], int n, int m, int row, int col)
{
    if(row>=0 && col>=0 && row<n && col<m && maze[row][col]!='X')
    {
        return true;
    }
    return false;
}

bool solve_maze_util(char maze[][MAX], int n, int m, int i, int j, int ans[][MAX])
{
    //goal is to reach maze[n][m]
    if(i==n-1 && j==m-1)
    {
        ans[i][j] = 1;
        return true;
    }

    //check current pos
    if( isSafe(maze, n, m, i, j) )
    {
        ans[i][j] = 1;

        //move forward to right
        if(solve_maze_util(maze, n, m, i, j+1, ans)==true)
        {
            return true;
        }

        //move down if not moved right
        if(solve_maze_util(maze, n, m, i+1, j, ans) == true)
        {
            return true;
        }

        //if neither move is possible then backtrack
        //unmark current position from solution
        ans[i][j] = 0;
        return false;
    }

    //not safe 
    return false;
}

void solve_maze(char maze[][MAX], int n, int m)
{
    int ans[n][MAX];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            ans[i][j] = 0;
        }
    }

    if(solve_maze_util(maze, n, m, 0, 0, ans) == false)
    {
        cout << -1 << endl;
        return;
    }

    print_soln(ans, n, m);
    return;
}

int main()
{
    int m, n;
    cin >> n >> m;

    char board[n][MAX];
    //O - empty, X - blocked
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> board[i][j];
        }
    }

    solve_maze(board, n, m);

    return (0);
}