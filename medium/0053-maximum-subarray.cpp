////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 53. Maximum Subarray
// Difficulty : Medium
// Link       : https://leetcode.com/problems/maximum-subarray/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Kadane's algorithm | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 71.8 MB
// Date       : 2026-05-25
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum >= max){
                max = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return max;
    }
};