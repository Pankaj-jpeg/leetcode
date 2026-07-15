////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 162. Find Peak Element
// Difficulty : Medium
// Link       : https://leetcode.com/problems/find-peak-element/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 12.6 MB
// Date       : 2026-07-15
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;

        if(n == 1)
            return 0;
        
        if(n==2)
            return nums[0] > nums[1] ? 0 : 1;

        while(low<high){
            mid = low + (high-low)/2;
            
            if(mid == 0){
                return nums[mid] > nums[mid+1] ? mid : mid+1;
            }
            if(mid == n-1){
                return nums[mid-1] < nums[mid] ? mid : mid-1;
            }


            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid-1] > nums[mid]){
                high = mid-1;
            }
            else
                low = mid+1;
        }

        return low;
    }
};