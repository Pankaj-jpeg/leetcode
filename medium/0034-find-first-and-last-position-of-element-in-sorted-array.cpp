////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 34. Find First and Last Position of Element in Sorted Array
// Difficulty : Medium
// Link       : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: modified binary search | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 17.6 MB
// Date       : 2026-06-26
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low  = 0;
        int high = nums.size()-1;
        int mid;

        if(nums.size() == 0)
            return {-1,-1};

        while(low<high){
            mid = low + (high-low)/2;
            if(target<=nums[mid])
                high = mid;
            else
                low = mid+1;
        }
        if(nums[low]!=target)
            return {-1,-1};


        while(high < nums.size() && nums[high] == target)
            high++;

        return {low,high-1};
    }
};