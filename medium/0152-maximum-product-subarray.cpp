////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 152. Maximum Product Subarray
// Difficulty : Medium
// Link       : https://leetcode.com/problems/maximum-product-subarray/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two passes, one from left to right and one from right to left, to find maximum product subarray | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 17.6 MB
// Date       : 2026-06-04
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=INT_MIN;
        int prod1=1;int prod2=1;
        for(int i=0;i<nums.size();i++){
            prod1*=nums[i];
            if(prod1 > max1)
                max1 = prod1;
            if(prod1 == 0)
                prod1 = 1;     
        }
        int max2=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            prod2*=nums[i];
            if(prod2 > max2)
                max2 = prod2;
            if(prod2 == 0)
                prod2 = 1;     
        }
        int maxi = max(max1,max2);
        return maxi;
    }
};