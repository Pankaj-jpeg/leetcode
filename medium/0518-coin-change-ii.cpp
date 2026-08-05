////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 518. Coin Change II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/coin-change-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with bottom-up iteration | Time: O(n*amount) | Space: O(amount)
// Time       : 
// Space      : 
// Runtime    : 28 ms  |  Memory: 10 MB
// Date       : 2026-08-05
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int idx = 0;
        vector<int> dp(amount+1,-1);
        for(int i = n;i>=0;i--){
            for(int j = 0;j<=amount;j++){
                if(j == 0 && i == n)
                    dp[j] = 1;
                else if(i == n)
                    dp[j] = 0;
                else if(j - coins[i] < 0)
                    dp[j] = dp[j];
                else{
                    if(((long)dp[j-coins[i]] + (long)dp[j]) < INT_MAX)
                        dp[j] = dp[j-coins[i]] + dp[j];
                    else
                        dp[j] = 0;
                }
            }
        }

        return dp[amount];
    }
};