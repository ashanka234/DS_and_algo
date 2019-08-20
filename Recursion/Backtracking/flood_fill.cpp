#include<iostream>
using namespace std;

void floodFillUtil(int mat[][10], int n, int m, int x, int y, int p, int newCol)
{
    //base case
    if(x<0 || x>=n || y<0 || y>=m)
        return;

    if(mat[x][y] != p)      //this color ended
        return;

    mat[x][y] = newCol;

    floodFillUtil(mat, n, m, x+1, y, p, newCol);
    floodFillUtil(mat, n, m, x, y+1, p, newCol);
    floodFillUtil(mat, n, m, x-1, y, p, newCol);
    floodFillUtil(mat, n, m, x, y-1, p, newCol);
}

void floodFill(int mat[][10], int n, int m, int x, int y, int newColor)
{
    int prevColor = mat[x][y];

    floodFillUtil(mat, n, m, x, y, prevColor, newColor);
}

int main()
{
    int t, n, m;
    int x, y, newColor;
    int mat[10][10];

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> mat[i][j];
            }
        }

        cin >> x >> y >> newColor;

        floodFill(mat, n, m, x, y, newColor);

        //print updated matrix
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << mat[i][j] << " ";
            }
        }
        cout << endl;
    }

    return (0);
}