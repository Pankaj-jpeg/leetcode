////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 283. Move Zeroes
// Difficulty : Easy
// Link       : https://leetcode.com/problems/move-zeroes/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique, one for non-zero elements and one for zero fill | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 23.9 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;

        while(j<n){
            if(nums[j] == 0)
                j++;
            else{
                nums[i++] = nums[j];
                j++;
            }
        }

        while(i<n){
            nums[i] = 0;
            i++;
        }
    }
};