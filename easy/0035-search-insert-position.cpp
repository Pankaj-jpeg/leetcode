////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 35. Search Insert Position
// Difficulty : Easy
// Link       : https://leetcode.com/problems/search-insert-position/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 13.6 MB
// Date       : 2026-06-04
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low =0;
        int high = nums.size()-1;
        int mid;
        if(nums.size()==1){
            if(nums[0] >= target){
                return 0;
            }
            else{
                return 1; 
            }
        }

        while(low<=high){
            mid = low + (high-low)/2;
            if(target > nums[mid])
                low = mid +1;
            else if (target < nums[mid])
                high = mid-1;
            else
                return mid;
        }
        return low;
    }
};