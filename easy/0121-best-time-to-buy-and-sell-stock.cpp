////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 121. Best Time to Buy and Sell Stock
// Difficulty : Easy
// Link       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: single pass, keep track of min price and max profit | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 97.3 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Max = 0;
        int Min = INT_MAX;
        int profit;

        for(int i = 0;i<prices.size();i++){
            Min = min(Min,prices[i]);
            profit = prices[i] - Min;
            Max = max(Max,profit);
        }
        return Max;
    }
};