////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 33. Search in Rotated Sorted Array
// Difficulty : Medium
// Link       : https://leetcode.com/problems/search-in-rotated-sorted-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search with rotation detection | Time: O(log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 15.2 MB
// Date       : 2026-06-05
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        if(nums.size()==1){
            if(nums[0] == target)
                return 0;
            else
                return -1;
        }
        while(low<=high){
            mid = low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target<=nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            else{
                if(nums[mid] <= target && target<=nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }

        return -1;
    }
};