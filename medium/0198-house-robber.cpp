////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 198. House Robber
// Difficulty : Medium
// Link       : https://leetcode.com/problems/house-robber/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with bottom-up approach | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 10.1 MB
// Date       : 2026-07-29
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);


        int next_to_next=nums[n-1];
        int next = max(nums[n-2],nums[n-1]);
        int curr;

        for(int i = n-3;i>=0;i--){
            curr = max(nums[i] + next_to_next,next);
            next_to_next = next;
            next = curr;
        }

        return curr;
    }
};