////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 137. Single Number II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/single-number-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: bitwise manipulation, using XOR and bitwise AND to track counts of 1s and 2s | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 13.3 MB
// Date       : 2026-06-23
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos =0;

        for (auto num : nums){
            ones = ones ^ num &(~twos);
            twos = twos ^ num &(~ones);
        }

        return ones;
    }
};