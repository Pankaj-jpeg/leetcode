////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 300. Longest Increasing Subsequence
// Difficulty : Medium
// Link       : https://leetcode.com/problems/longest-increasing-subsequence/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 13.9 MB
// Date       : 2026-08-25
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        for(int i = 0;i<n;i++){
            if(len == 0 || nums[len-1] < nums[i]) nums[len++] = nums[i];
            else *lower_bound(nums.begin(),nums.begin()+len,nums[i]) = nums[i];
        }
        
        return len;        
    }
};