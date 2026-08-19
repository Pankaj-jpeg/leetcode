////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 309. Best Time to Buy and Sell Stock with Cooldown
// Difficulty : Medium
// Link       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 14.9 MB
// Date       : 2026-08-19
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(3,0);


        for(int i = n-1;i>=0;i--){
            int prev = dp[0];
            for(int t = 0;t<=2;t++){
                 if(t == 0)
                    dp[t] = max(-prices[i] + dp[1],dp[0]);
                else if(t == 1)
                    dp[t] = max(prices[i] + dp[2],dp[1]);
                else
                    dp[t] = prev;
            }
        }


        return dp[0];
    }
};