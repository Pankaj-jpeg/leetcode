////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 213. House Robber II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/house-robber-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with two separate states | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 10.3 MB
// Date       : 2026-07-29
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        if(n == 2)
            return max(nums[0],nums[1]);

        

        int ntn1 = 0;
        int ntn2 = nums[n-1];
        int curr1;

        int nex1 = nums[n-2];
        int nex2 = max(nums[n-1],nums[n-2]);
        int curr2;

        for(int i = n-3;i>=1;i--){
            curr1 = max(nums[i] + ntn1,nex1);
            ntn1 = nex1;
            nex1 = curr1;

            curr2 = max(nums[i] + ntn2,nex2);
            ntn2 = nex2;
            nex2 = curr2;
        }
        return max(nums[0] + ntn1,nex2);
    }
};