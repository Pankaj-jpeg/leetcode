////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 714. Best Time to Buy and Sell Stock with Transaction Fee
// Difficulty : Medium
// Link       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 63.6 MB
// Date       : 2026-08-19
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int b1 = 0,s1 = 0,b2 = 0,s2 = 0;
        
        for(int i = n-1;i>=0;i--){
            for(int t = 0;t<=1;t++){
                if(t == 0)
                    b1 = max(-prices[i]-fee + s2,b2);
                else    
                    s1 = max(prices[i] + b2,s2);
            }

            b2 = b1;
            s2 = s1;
        }


        return b1;
    }
};