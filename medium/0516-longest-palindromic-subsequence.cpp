////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 516. Longest Palindromic Subsequence
// Difficulty : Medium
// Link       : https://leetcode.com/problems/longest-palindromic-subsequence/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with two pointers | Time: O(n^2) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 68 ms  |  Memory: 9.3 MB
// Date       : 2026-08-12
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        //reverse(s2.begin(),s2.end());

        int n = s.size();

        vector<int> dp(n+1,0);
        vector<int> prev(n+1,0);
        

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                prev[j] = dp[j];
                if(s[i-1] == s2[n-j])
                    dp[j] = 1 + prev[j-1];
                else
                    dp[j] = max(dp[j-1],dp[j]);
            }
        }


        return dp[n];

    }
};