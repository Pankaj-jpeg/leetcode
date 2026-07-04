////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3979. Maximum Valid Pair Sum
// Difficulty : Medium
// Link       : https://leetcode.com/problems/maximum-valid-pair-sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: prefix max array | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 4 ms  |  Memory: 215.5 MB
// Date       : 2026-07-04
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
       
        int n = nums.size();
         vector<int> Max(n);
        Max[0]=nums[0];
        for(int i=1;i<n;i++){
            Max[i] = max(Max[i-1],nums[i]);
        }
        int res = INT_MIN;
        for(int i=k;i<n;i++){
            res = max(res,Max[i-k] + nums[i]);
        }
        return res;
    }
};