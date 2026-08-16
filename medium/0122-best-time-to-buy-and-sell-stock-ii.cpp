////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 122. Best Time to Buy and Sell Stock II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: single pass, maintaining minimum price and adding positive differences | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 19.9 MB
// Date       : 2026-08-16
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int Min = INT_MAX;
        for(int it : prices){
            Min = min(Min,it);
            profit+=(it - Min);
            if(it-Min > 0)
                Min = it;
        }

        return profit;
    }
};