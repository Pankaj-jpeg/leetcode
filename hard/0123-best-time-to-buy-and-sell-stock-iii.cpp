////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 123. Best Time to Buy and Sell Stock III
// Difficulty : Hard
// Link       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 19 ms  |  Memory: 79.4 MB
// Date       : 2026-08-19
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(4,0)));
        vector<vector<int>> dp(3,vector<int>(4,0));
        for(int i = n-1;i>=0;i--){
            for(int cnt = 2;cnt>=0;cnt--){
                for(int buy = 0;buy<=1;buy++){
                    long profit = 0;
                    if(buy){ 
                        profit = max((-prices[i] + dp[0][cnt+1]) , dp[1][cnt]);
                    }
                    else
                        profit = max(prices[i] + dp[1][cnt],dp[0][cnt]);

                    dp[buy][cnt] = profit;
                }
            }
        }
        return dp[1][0];
    }
};