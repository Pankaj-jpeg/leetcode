////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 583. Delete Operation for Two Strings
// Difficulty : Medium
// Link       : https://leetcode.com/problems/delete-operation-for-two-strings/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with bottom-up approach | Time: O(n*m) | Space: O(m))
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 11 MB
// Date       : 2026-08-12
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> dp(m+1,0);

        for(int i = 1;i<=n;i++){
            int prev = 0;
            for(int j = 1;j<=m;j++){
                int temp = dp[j];
                if(word1[i-1] == word2[j-1])
                    dp[j] = 1 + prev;
                else    
                    dp[j] = max(dp[j-1],dp[j]);
                prev = temp;
            }
        }


        return  n+m-2*dp[m];
    }
};