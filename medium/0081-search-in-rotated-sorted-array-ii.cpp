////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 81. Search in Rotated Sorted Array II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: modified binary search | Time: O(log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 18 MB
// Date       : 2026-06-26
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
       

        while(low<high){
            mid = low + (high-low)/2;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target<=nums[mid])
                    high = mid;
                else
                    low = mid+1;
            }
            else{
                if(nums[mid] < target && target <= nums[high])
                    low = mid+1;
                else    
                    high = mid;
            }
        }

        if(nums[low] == target)
            return true;
        else
            return false;
    }
};