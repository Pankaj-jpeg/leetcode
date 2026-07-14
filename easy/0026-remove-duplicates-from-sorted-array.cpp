////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 26. Remove Duplicates from Sorted Array
// Difficulty : Easy
// Link       : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique, increment right pointer on unique element, increment left pointer on unique element | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 22.7 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int n = nums.size();
        while(j<n){
            if(nums[j] == nums[j-1]){
                j++;
            }
            else{
                nums[++i] = nums[j];
                j++;
            }
        }

        return i+1;
    }
};