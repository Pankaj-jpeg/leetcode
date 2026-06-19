////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 540. Single Element in a Sorted Array
// Difficulty : Medium
// Link       : https://leetcode.com/problems/single-element-in-a-sorted-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: modified binary search | Time: O(log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 26.2 MB
// Date       : 2026-06-08
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        int n = nums.size();
        int k;
        int res=-1;
        if(n==1){
            return nums[0];
        }
        while(low<=high){
            mid = low + (high-low)/2;
            k = (high-low)/2;
            if(k==0){
                res = nums[mid];
                break;
            }
            if(k%2==0){
                if(nums[mid-1] == nums[mid])
                    high = mid;
                else if(nums[mid+1] == nums[mid])
                    low = mid;
                else{
                    res = nums[mid];
                    break;
                }
            }
            else{
                if(nums[mid-1] == nums[mid])
                    low = mid+1;
                else if(nums[mid+1] == nums[mid])
                    high = mid-1;
                else{
                    res = nums[mid];
                    break;
                }
            }
        }
        return res;
    }
};