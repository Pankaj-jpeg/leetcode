////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 72. Edit Distance
// Difficulty : Medium
// Link       : https://leetcode.com/problems/edit-distance/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with bottom-up approach | Time: O(n*m) | Space: O(m))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 10.3 MB
// Date       : 2026-08-16
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> dp(m+1,0);

        for(int i = 0;i<=m;i++)
            dp[i] = i;


        for(int i = 1;i<=n;i++){
            int prev = dp[0];
            dp[0] = i;
            for(int j = 1;j<=m;j++){
                int temp = dp[j];
                if(word1[i-1] == word2[j-1])
                    dp[j] = prev;
                else
                    dp[j] = min(dp[j-1],min(dp[j],prev)) + 1;
                prev = temp;
            }
        }

        return dp[m];
    }
};