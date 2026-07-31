////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 120. Triangle
// Difficulty : Medium
// Link       : https://leetcode.com/problems/triangle/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with bottom-up approach | Time: O(n*m) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 12.5 MB
// Date       : 2026-07-31
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<int>dp(n,INT_MAX);

        int r = 0;
        int c = 0;
        
        dp[0] = triangle[0][0];
        if(triangle.size() == 1)
            return dp[0];
        int Min = INT_MAX;

        for(int i = 1;i<triangle.size();i++){   
            for(int j=triangle[i].size()-1;j>=0;j--){
                if(j == 0)
                    dp[j] += triangle[i][j];

                else if(j == triangle[i].size()-1)
                    dp[j] = triangle[i][j] + dp[j-1];
                else
                    dp[j] = triangle[i][j] + min(dp[j],dp[j-1]);

                if(i == triangle.size()-1)
                    Min = min(Min,dp[j]);
            }  
        }


        return Min;
    }
};