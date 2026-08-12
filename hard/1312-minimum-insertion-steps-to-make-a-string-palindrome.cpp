////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1312. Minimum Insertion Steps to Make a String Palindrome
// Difficulty : Hard
// Link       : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with memoization | Time: O(n^2) | Space: O(n^2))
// Time       : 
// Space      : 
// Runtime    : 31 ms  |  Memory: 31.4 MB
// Date       : 2026-08-12
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int f(string& a,vector<vector<int>>& dp,int i,int j){
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(a[i] == a[j])
            return dp[i][j] = f(a,dp,i+1,j-1);
        else
            return dp[i][j] = 1 + min(f(a,dp,i+1,j),f(a,dp,i,j-1));
    }
    int minInsertions(string s) {
        int n = s.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));


        return f(s,dp,0,n-1);
    }
};