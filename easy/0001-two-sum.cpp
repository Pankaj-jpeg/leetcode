////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1. Two Sum
// Difficulty : Easy
// Link       : https://leetcode.com/problems/two-sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: hash table, store numbers and their indices | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 1 ms  |  Memory: 15 MB
// Date       : 2026-06-24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> map;
        for(int i = 0;i<nums.size();i++){
            if(map.find(target-nums[i]) != map.end())
                return {map.find(target-nums[i])->second,i};
            map[nums[i]] = i;
        }
        return {0,0};
    }
};