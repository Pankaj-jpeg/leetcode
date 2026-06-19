////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 81. Search in Rotated Sorted Array II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search with special handling for duplicate elements | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 18.1 MB
// Date       : 2026-06-05
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        if(nums.size()==1){
            if(nums[0] == target)
                return true;
            else
                return false;
        }
        //bool flag;
        while(low<=high){
            //flag = true;
            mid = low+(high-low)/2;
            if(nums[mid]==target)
                return true;
            if(nums[low] == nums[high] && nums[high] == nums[mid]){
                low++;
                high--;
                continue;
            }
            
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

        return false;
    }
};