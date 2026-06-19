////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 90. Subsets II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/subsets-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: backtracking with duplicate handling | Time: O(2^n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 2 ms  |  Memory: 11 MB
// Date       : 2026-06-18
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    set<vector<int>> res; vector<int> curr = {};
    void generator(vector<int>& nums,int idx){
        if(idx == nums.size()){
            res.insert(curr);
            return;
        }
        curr.push_back(nums[idx]);
        generator(nums,idx+1);
        curr.pop_back();
        generator(nums,idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int idx = 0;
        sort(nums.begin(),nums.end());
        generator(nums,0);

        vector<vector<int>> result;
        for(auto itr : res){
            result.push_back(itr);
        }
        return result;
    }
};