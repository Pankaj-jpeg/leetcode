////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 540. Single Element in a Sorted Array
// Difficulty : Medium
// Link       : https://leetcode.com/problems/single-element-in-a-sorted-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search with adjustment of search space | Time: O(log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 26.2 MB
// Date       : 2026-07-15
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;

        while(low<high){
            mid = low + (high-low)/2;

            if(mid == 0 || mid == n-1)
                break;


            if(nums[mid] == nums[mid+1]){
                if((mid-low+1)%2 == 0){
                    high = mid-1;
                }
                else{
                    low = mid;
                }
            }

            else{
                if((mid-low+1)%2 == 0){
                    low = mid+1;
                }
                else
                    high = mid;
            }
        }

        return nums[low];
    }
};