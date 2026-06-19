////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 75. Sort Colors
// Difficulty : Medium
// Link       : https://leetcode.com/problems/sort-colors/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Dutch National Flag algorithm | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 11.5 MB
// Date       : 2026-05-24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};