////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 121. Best Time to Buy and Sell Stock
// Difficulty : Easy
// Link       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: single pass, keep track of min price and max profit | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 97.3 MB
// Date       : 2026-08-16
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Max = 0;
        int Min = INT_MAX;

        for(int it : prices){
            Min = min(Min,it);
            Max = max(Max,it-Min);
        }

        return Max;
    }
};