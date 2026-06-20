////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 216. Combination Sum III
// Difficulty : Medium
// Link       : https://leetcode.com/problems/combination-sum-iii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: backtracking with depth-first search | Time: O(9^k) | Space: O(k)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.7 MB
// Date       : 2026-06-19
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr={};vector<int> nums = {1,2,3,4,5,6,7,8,9};int sum=0;int cnt=0;
    void generator(int k,int n,int idx){
        if(cnt == k && sum == n){
            res.push_back(curr);
            return;
        }

        for(int i = idx;i<nums.size();i++){
            curr.push_back(nums[i]);
            sum+=nums[i];cnt++;
            generator(k,n,i+1);
            sum-=nums[i];cnt--;
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        generator(k,n,0);
        return res;
    }
};