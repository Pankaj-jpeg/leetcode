////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 39. Combination Sum
// Difficulty : Medium
// Link       : https://leetcode.com/problems/combination-sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: backtracking with depth-first search | Time: O(2^n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 14.4 MB
// Date       : 2026-07-17
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> res; vector<int> curr={};
    void generator(vector<int>& candidates,int idx,int sum,int target){
        if(idx == candidates.size())
            return;
        if(sum == target){
            res.push_back(curr);
            return;
        }
        if(sum > target){
            return;
        }
        
        for(int i = idx ;i < candidates.size();i++){
            if(sum + candidates[i] > target) break;
            curr.push_back(candidates[i]);
            sum+=candidates[i];
            generator(candidates,i,sum,target);
            curr.pop_back();
            sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        generator(candidates,0,0,target);
        //vector<vector<int>> myvec(res.begin(),res.end());
        return res;
    }
};