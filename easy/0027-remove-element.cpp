////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 27. Remove Element
// Difficulty : Easy
// Link       : https://leetcode.com/problems/remove-element/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique, one for iterating through the array and one for keeping track of the position to place non-target elements | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 11.7 MB
// Date       : 2026-01-10
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != val){
                nums[k]=nums[i];
                k++;
                
            }
        }
        return k;
    }
};