#include<iostream>
#include<vector>
#include<string>

using namespace std;

string longestPalindrome(string s)
{
        int n = s.size();
        vector <vector <int>> dp (n , vector <int> (n , 0));
        int longestP = -1;
        int len_longestP = 0;

        for (int i = 0 ; i < n ; i++)
            dp[i][i] = 1;

        for (int i = 0 ; i < n-1 ; i++)
            if (s[i]==s[i+1])
            {
                dp[i][i+1] = 1;
                longestP = i;
                len_longestP = 2;
            }

        for (int len = 3 ; len <= n ; len++)
        {
            for (int i = 0 ; i <= n - len ; i++)
            {
                int j = i + len - 1;
                if (dp[i+1][j-1] == 1 && s[i] == s[j])
                {
                    dp[i][j] = 1;
                    len_longestP = len;
                    longestP = i;
                }
            }
        }
        cout<<"Input string: "<<s<<". len(s) = "<<s.size()<<endl;
        cout<<longestP<<endl;
        return (longestP > 0) ? s.substr(longestP , len_longestP) : "";
}

int main()
{
    string s ("civicisnot0123210becauseMALAYALAM");
    string op = longestPalindrome(s);
    for (int i = 0 ; i < op.size() ; i++)
        cout<<op[i]<<" ";
    cout<<endl;
}
