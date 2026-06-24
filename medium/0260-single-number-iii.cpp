////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 260. Single Number III
// Difficulty : Medium
// Link       : https://leetcode.com/problems/single-number-iii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: bitwise XOR and divide into two groups | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 13.9 MB
// Date       : 2026-06-24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i =0;i<nums.size();i++){
            res^=nums[i];
        }

        int g1 = 0;
        int g2 = 0;
        int set = 0;
        for(int i = 0;i<32;i++){
            if((1 << i)&res) set = 1<<i;
        }

        for(int i =0;i<nums.size();i++){
            if(set&nums[i]) g1^=nums[i];
            else g2^=nums[i];
        }
        return {g1,g2};

    }
};