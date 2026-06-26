////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 35. Search Insert Position
// Difficulty : Easy
// Link       : https://leetcode.com/problems/search-insert-position/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 13.5 MB
// Date       : 2026-06-26
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low =0;
        int high = nums.size()-1;
        int mid;

        while(low<high){
            mid = low + (high-low)/2;
            if(target <= nums[mid])
                high = mid;
            else 
                low = mid+1;
        }
        if(low == nums.size()-1 && target > nums[low])  
            return nums.size();
        return low;
    }
};