////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 64. Minimum Path Sum
// Difficulty : Medium
// Link       : https://leetcode.com/problems/minimum-path-sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming | Time: O(m*n) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 15.5 MB
// Date       : 2026-07-31
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n);
        dp[0] = grid[0][0];
        for(int r = 0;r<m;r++){
            for(int c = 0;c<n;c++){
                if(r == 0 && c==0)
                    continue;
                if(r == 0 && c>0)
                    dp[c] = grid[0][c] + dp[c-1];
                
                else if(c==0)
                    dp[c] += grid[r][c];
                else{
                    dp[c] = grid[r][c] + min(dp[c],dp[c-1]);
                }
            }
        }


       return dp[n-1];
    }
};