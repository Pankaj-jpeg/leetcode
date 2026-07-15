////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 154. Find Minimum in Rotated Sorted Array II
// Difficulty : Hard
// Link       : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: modified binary search with duplicate handling | Time: O(log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 16.1 MB
// Date       : 2026-07-15
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findMin(vector<int>& nums) {
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

            if(nums[mid] <= nums[high])
                high = mid;
            else
                low = mid+1;
        }

        return nums[low];
    }
};