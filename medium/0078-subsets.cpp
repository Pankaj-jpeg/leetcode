////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 78. Subsets
// Difficulty : Medium
// Link       : https://leetcode.com/problems/subsets/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: bit manipulation to generate all possible subsets | Time: O(n*p) | Space: O(n*p))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 9.8 MB
// Date       : 2026-06-23
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;vector<int> curr={};
        int n = nums.size();
        int p = 1<<n;

        for(int i = 0;i<p;i++){
            for(int j=0;j<n;j++){
                if(i & (1 << (n-j-1))){
                    curr.push_back(nums[j]);
                }
            }
            res.push_back(curr);
            curr.clear();
        }
        return res;
    }
};