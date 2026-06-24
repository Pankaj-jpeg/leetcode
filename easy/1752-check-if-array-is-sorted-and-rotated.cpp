////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1752. Check if Array Is Sorted and Rotated
// Difficulty : Easy
// Link       : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: single pass, checking for increasing sequence | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 11.3 MB
// Date       : 2026-06-24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] > nums[(i+1)%n]) cnt++;
            if(cnt>1)return false;
        }
        return true;
    }
};