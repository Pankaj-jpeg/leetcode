////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 121. Best Time to Buy and Sell Stock
// Difficulty : Easy
// Link       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: single pass, keep track of minimum price and maximum profit | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 97.5 MB
// Date       : 2026-05-25
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int min=nums[0];int max_prof=0;int profit=0;
        for(int i=0;i<nums.size();i++){
            profit = nums[i]-min;
            if(profit > max_prof){
                max_prof = profit;
            }
            if(nums[i]<min){
                min = nums[i];
            }
       } 
       return max_prof;
    } 
};