////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 115. Distinct Subsequences
// Difficulty : Hard
// Link       : https://leetcode.com/problems/distinct-subsequences/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with bottom-up tabulation | Time: O(n*m) | Space: O(m))
// Time       : 
// Space      : 
// Runtime    : 13 ms  |  Memory: 8.6 MB
// Date       : 2026-08-12
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public: 
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> dp(m+1,0);

        for(int i = n;i>=0;i--){
            int prev = 0;
            for(int j = m;j>=0;j--){
                int temp = dp[j];
                if(j == m)
                    dp[j] = 1;
                else if(i == n)
                    dp[j] = 0;
                else if(s[i] == t[j]){
                    if((long)prev + (long)dp[j] > INT_MAX)
                        dp[j] = -1;
                    else
                        dp[j] = prev + dp[j];
                }
                else    
                    dp[j] = dp[j];
                prev = temp;
            }
        }

        return dp[0];
    }
};