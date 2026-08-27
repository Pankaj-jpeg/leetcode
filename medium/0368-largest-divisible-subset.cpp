////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 368. Largest Divisible Subset
// Difficulty : Medium
// Link       : https://leetcode.com/problems/largest-divisible-subset/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 7 ms  |  Memory: 12.6 MB
// Date       : 2026-08-26
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n+1,1),hash(n+1);
        int Max = INT_MIN;
        int lastindex;
        for(int i = 0;i<n;i++){
            hash[i] = i;
            for(int prev = 0;prev<i;prev++){
                if(nums[i]%nums[prev] == 0 && dp[i] < 1 + dp[prev]){
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if(dp[i] > Max){
                Max = dp[i];
                lastindex = i;
            }
        }
        vector<int> res;
        while(hash[lastindex] != lastindex){
            res.push_back(nums[lastindex]);
            lastindex = hash[lastindex];
        }
        res.push_back(nums[lastindex]);
        return res;
    }
};