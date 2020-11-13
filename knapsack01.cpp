#include<iostream>
#include<vector>
#include<string>

using namespace std;

int knapsack (int capacity , vector <int> & w , vector <int> & v)
{
    int n = w.size();
    vector <vector <int>> tab (n+1 , vector<int> (capacity+1 , -1));

    //tab[i][j] = max value of knapsack of capacity j
    //filled by elements with sizes s[0] to s[i]
    for (int i = 0 ; i <= n ; i++)
        tab[i][0] = 0;

    for (int j = 0 ; j <= capacity ; j++)
        tab[0][j] = 0;

    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= capacity ; j++)
        {
            if (j - w[i] >= 0)
                tab[i][j] = max(tab[i-1][j] , tab[i][j - w[i]] + v[i]);
            else
                tab[i][j] = tab[i-1][j];
        }
    }
    return tab[n-1][capacity];

}

int main()
{
    vector <int> v {20, 5, 10, 40, 15, 25};
    vector <int> w {1, 2,  3,  8,  7, 4};
    int c = 10;
    cout<<knapsack(c , w , v);
}
