////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1. Two Sum
// Difficulty : Easy
// Link       : https://leetcode.com/problems/two-sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: hash table, store numbers and their indices | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 1 ms  |  Memory: 14.9 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;

        for(int i = 0;i<nums.size();i++){     
            if(m.find(target - nums[i])!=m.end()){
                return {m[target-nums[i]],i};
            }
            m.insert({nums[i],i});
        }


        return {};
    }
};