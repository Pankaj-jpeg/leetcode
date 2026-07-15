////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 153. Find Minimum in Rotated Sorted Array
// Difficulty : Medium
// Link       : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search, divide array into two halves | Time: O(log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 14.2 MB
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

            if(nums[mid] <= nums[high]){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }

        return nums[low];
    }
};