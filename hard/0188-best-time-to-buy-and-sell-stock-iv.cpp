////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 188. Best Time to Buy and Sell Stock IV
// Difficulty : Hard
// Link       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 14.2 MB
// Date       : 2026-08-19
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2*k+1,0);

        for(int i = n-1;i>=0;i--){
            int prev = 0;
            for(int t = 2*k-1;t>=0;t--){
                int temp = dp[t];
                if(t%2==0)
                    dp[t] = max(-prices[i] + prev,dp[t]);
                else    
                    dp[t] = max(prices[i] + prev, dp[t]);
                prev = temp;
            }
        }

        return dp[0];
    }
};