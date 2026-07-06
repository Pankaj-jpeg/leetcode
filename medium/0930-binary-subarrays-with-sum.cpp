////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 930. Binary Subarrays With Sum
// Difficulty : Medium
// Link       : https://leetcode.com/problems/binary-subarrays-with-sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: prefix sum with sliding window | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 32.6 MB
// Date       : 2026-07-06
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal) - atMost(nums,goal-1);  
    }

    int atMost(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n = nums.size();
        int cnt = 0;
        int l = 0;
        int sum = 0;
        for(int r = 0;r<n;r++){
            sum+=nums[r];
            while(sum > goal){
                sum-=nums[l];
                l++;
            }
            cnt += r-l+1;
        }
        return cnt;
    }
};