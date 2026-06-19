////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 26. Remove Duplicates from Sorted Array
// Difficulty : Easy
// Link       : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique, increment right on unique | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 22.6 MB
// Date       : 2026-05-24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[j])
            {
                j++;
                nums[j]=nums[i];
            }
        }
        return j+1;
    }
};