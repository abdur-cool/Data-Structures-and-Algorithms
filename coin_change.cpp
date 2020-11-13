#include<iostream>
#include<limits>
#include<vector>

using namespace std;


void print_matrix(vector <vector<int>> & matrix)
{
    int r = matrix.size();      //rows
    int c = matrix[1].size();    //columns
    for (int i = 0 ;  i < r ; i++)
    {
        for (int j = 0 ; j < c ; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

long getWays(int n, vector<long> c)
{
    int m = c.size();
    vector <vector<long>> ways (m+1, vector<long> (n+1,0));
    for (int i = 0 ; i <= m ; i++)
        ways[i][0] = 1;
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            if (j - c[i-1] >= 0)
                ways[i][j] = ways[i-1][j] + ways[i][j - c[i-1]];
            else
                ways[i][j] = ways[i-1][j];
        }
    }
    return ways[m][n];
}

int main()
{
    vector <long> c {1,2,5};
    int n = 5;
    cout<<getWays(n,c);
}
