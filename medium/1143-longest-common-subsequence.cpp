////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1143. Longest Common Subsequence
// Difficulty : Medium
// Link       : https://leetcode.com/problems/longest-common-subsequence/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with bottom-up tabulation | Time: O(n*m) | Space: O(n*m)
// Time       : 
// Space      : 
// Runtime    : 19 ms  |  Memory: 9.2 MB
// Date       : 2026-08-11
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();


        vector<int> dp(m+1,0);
        vector<int> prev(m+1,0);
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                prev[j] = dp[j];
                if(text1[i-1] == text2[j-1]) 
                    dp[j] = 1 + prev[j-1];
                else
                    dp[j] = max(dp[j],dp[j-1]);
            }
        }
        return dp[m];
    }
};