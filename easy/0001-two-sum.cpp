////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1. Two Sum
// Difficulty : Easy
// Link       : https://leetcode.com/problems/two-sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: hash table, store numbers as keys and indices as values | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 14.9 MB
// Date       : 2026-05-24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            int req = target - nums[i];
            if(map.find(req)!=map.end()){
                int j = map[req];
                return {i,j};
            }
            else{
                map.insert({nums[i],i});
            }
        }
        return{0,0};
    }
};