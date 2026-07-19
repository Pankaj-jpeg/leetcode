////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 137. Single Number II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/single-number-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: bitwise XOR with two variables to track 'ones' and 'multi' bits | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 13.4 MB
// Date       : 2026-07-19
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int multi = 0;

        for(int i = 0;i<nums.size();i++){
            ones = (ones ^ nums[i])&(~multi);
            multi = (multi ^ nums[i])&(~ones);
        }

        return ones;
    }
};