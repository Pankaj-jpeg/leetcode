////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 153. Find Minimum in Rotated Sorted Array
// Difficulty : Medium
// Link       : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search, rotating point detection | Time: O(log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 14 MB
// Date       : 2026-06-05
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        if(nums[high]>nums[low])
            return nums[low];
        while(low<=high){
            mid = low + (high-low)/2;
            if(low==mid)
                break;
            if(nums[mid] > nums[low])
                low = mid;
            else
                high = mid;
        }

        return nums[high];
    }
};