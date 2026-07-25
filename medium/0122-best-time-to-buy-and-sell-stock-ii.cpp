////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 122. Best Time to Buy and Sell Stock II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: single pass, update minimum and add to profit on increase | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 19.9 MB
// Date       : 2026-07-25
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int Min = INT_MAX;
        for(int i = 0;i<n;i++){
            Min = min(Min,prices[i]);
            if(Min < prices[i]){
                profit+=(prices[i]-Min);
                Min = prices[i];
            }
        }
        return profit;
    }
};