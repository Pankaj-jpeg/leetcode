////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 40. Combination Sum II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/combination-sum-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: backtracking with pruning | Time: O(2^n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 14.3 MB
// Date       : 2026-06-18
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> res; vector<int> curr={};
    void generator(vector<int>& candidates,int idx,int sum,int target){
            if(sum == target){
                res.push_back(curr);
                return;
            }

        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            if(sum+candidates[i] > target) break;
            curr.push_back(candidates[i]);
            sum+=candidates[i];
            generator(candidates,i+1,sum,target);
            curr.pop_back();
            sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum = 0;
        sort(candidates.begin(),candidates.end());
        generator(candidates,0,0,target);
        return res;
    }
};