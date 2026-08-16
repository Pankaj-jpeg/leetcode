////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 44. Wildcard Matching
// Difficulty : Hard
// Link       : https://leetcode.com/problems/wildcard-matching/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with two nested loops | Time: O(n*m) | Space: O(m))
// Time       : 
// Space      : 
// Runtime    : 38 ms  |  Memory: 9.8 MB
// Date       : 2026-08-16
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> dp(m+1,false);

        dp[0] = true;

        for(int i = 1;i<=m;i++){
            if(p[i-1] == '*')
                dp[i] = dp[i-1];
        }


        for(int i = 1;i<=n;i++){
            bool prev = dp[0];
            dp[0] = false;
            for(int j = 1;j<=m;j++){
                bool temp = dp[j];
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[j] = prev;
                else if(p[j-1] == '*')
                    dp[j] = (dp[j] || dp[j-1]);
                else
                    dp[j] = false;
                prev = temp;
            }
        }
        return dp[m];
    }
};