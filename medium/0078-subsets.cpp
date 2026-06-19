////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 78. Subsets
// Difficulty : Medium
// Link       : https://leetcode.com/problems/subsets/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: backtracking | Time: O(2^n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 10 MB
// Date       : 2026-06-18
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> res;vector<int> curr={};
    void generator(vector<int>& nums,int idx){
        res.push_back(curr);
        for(int i=idx;i<nums.size();i++){
            curr.push_back(nums[i]);
            generator(nums,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        generator(nums,0);
        return res;
    }
};