////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 162. Find Peak Element
// Difficulty : Medium
// Link       : https://leetcode.com/problems/find-peak-element/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: modified binary search | Time: O(log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 12.6 MB
// Date       : 2026-06-08
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;
        if(n==1){
            return 0;
        }
        while(low <= high){
            mid = low + (high - low)/2;
            if(mid == 0 && nums[mid+1] < nums[mid]){
                break;
            }
            else if(mid == n-1 && nums[mid-1] < nums[mid])
                break;
            
            if(mid>0 && mid < n-1 && nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
                break;
            if(mid >0 && nums[mid-1] > nums[mid])
                high = mid-1;
            else if(mid <n-1 && nums[mid+1] > nums[mid])
                low = mid+1;
        }
        return mid;
    }
};