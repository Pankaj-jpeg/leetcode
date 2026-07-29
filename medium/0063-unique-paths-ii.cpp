////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 63. Unique Paths II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/unique-paths-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming | Time: O(m*n) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 11.4 MB
// Date       : 2026-07-29
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n,0);


        for(int r = 0;r<=m-1;r++){
            for(int c = 0;c<=n-1;c++){
                if(obstacleGrid[r][c])
                    dp[c] = 0;
                else if(r == 0 && c == 0)
                    dp[c] = 1;
                else if(r == 0)
                    dp[c] = dp[c-1];
                else if (c == 0)
                    continue;
                else
                    dp[c] += dp[c-1];
            }
        }

        return dp[n-1];
    }
};