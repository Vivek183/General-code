#include<stdio.h>
#include<bits/stdc++.h>

using namespace std ; 


int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        int ones, zeros;
        for (auto str : strs) {
            ones = count(str.begin(), str.end(), '1');
            zeros = count(str.begin(), str.end(), '0');
            for (int i = n; i >= ones; i--) {
                for (int j = m; j >= zeros; j--) {
                    
                    // In each cell, we check the max between using the current string or not.
                    // dp[i][j] is the previous value in the cell - not using the current str.
                    // dp[i - ones][j - zeros] is the value if we want to use the current string.
                    // we add one because we are using another string.
                    
                    dp[i][j] = max(dp[i][j], dp[i - ones][j - zeros] + 1);
                }
            }


cout << " -------------------- for string  "<< str << endl ; 

            for(int i = 0 ; i <= n ; i++)
        {
            for(int j = 0 ; j <= m ; j++)
            {
                cout << dp[i][j] << " "; 
            }
            cout << endl ; 
        }
        cout << endl ; 


        }

        for(int i = 0 ; i <= n ; i++)
        {
            for(int j = 0 ; j <= m ; j++)
            {
                cout << dp[i][j] << " "; 
            }
            cout << endl ; 
        }
        return dp[n][m];
    }


    int main()
    {
        
        vector<string> strs = {"1 ", "0","101","1"};
        int m , n ; 
        m = 1, n = 2;
        int ans = findMaxForm(strs , m , n); 
        cout << ans ; 

        return 0 ; 

    }

