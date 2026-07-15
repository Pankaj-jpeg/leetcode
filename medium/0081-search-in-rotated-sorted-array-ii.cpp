////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 81. Search in Rotated Sorted Array II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: modified binary search | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 18.1 MB
// Date       : 2026-07-15
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;

        while(low<high){
            mid = low + (high-low)/2;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

            if(nums[mid] <= nums[high]){
                if(target > nums[mid] && target<=nums[high])
                    low = mid+1;
                else
                    high = mid;
            }
            else{
                if(target <= nums[mid] && target >= nums[low]){
                    high = mid;
                }
                else
                    low = mid+1;
            }
        }


        return nums[low] == target;
    }
};