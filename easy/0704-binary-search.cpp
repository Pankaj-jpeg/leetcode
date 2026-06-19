////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 704. Binary Search
// Difficulty : Easy
// Link       : https://leetcode.com/problems/binary-search/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(log n) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 31.4 MB
// Date       : 2026-06-04
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        if(nums.size()==1){
            if(target == nums[0])
                return 0;
            else
                return -1;
        }
            
        while(low<=high){
            mid = low + (high-low)/2;
            if(target > nums[mid]){
                low = mid+1;
            }
            else if(target < nums[mid]){
                high = mid-1;
            }
            else{
                return mid;
            }
            
        }

        return -1;
    }
};