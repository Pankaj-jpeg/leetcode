////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 283. Move Zeroes
// Difficulty : Easy
// Link       : https://leetcode.com/problems/move-zeroes/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique, one for non-zero elements and one for zero replacement | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 23.8 MB
// Date       : 2026-05-24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]!=0){
                nums[i] = nums[j];
                i++;
            }
        }
        while(i<nums.size()){
            nums[i] = 0;
            i++;
        }
    }
};