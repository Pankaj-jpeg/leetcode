////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1004. Max Consecutive Ones III
// Difficulty : Medium
// Link       : https://leetcode.com/problems/max-consecutive-ones-iii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique with dynamic adjustment | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 69.7 MB
// Date       : 2026-07-22
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int Max = 0;
        int cnt = 0;
        while(r<n){
            if(cnt<k){
                if(nums[r] == 0)
                    cnt++;
            }
            else{
                if(!nums[r]){
                    while(l<n && nums[l])
                        l++;
                    l++;
                }
            }
            Max = max(Max,r-l+1);
            r++;
        } 
        return Max;
    }
};