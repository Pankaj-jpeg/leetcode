////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 494. Target Sum
// Difficulty : Medium
// Link       : https://leetcode.com/problems/target-sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with memoization | Time: O(n*(k+1)) | Space: O(k+1))
// Time       : 
// Space      : 
// Runtime    : 5 ms  |  Memory: 12.4 MB
// Date       : 2026-08-05
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int idx = 0;
        int sum = 0;
        for(auto it:nums)
            sum+=it;
        if((target+sum)%2 != 0 || target+sum < 0)
            return 0;
        int k = (target+sum)/2;
        vector<int> dp(k+1,-1);
        for(int i = n;i>=0;i--){
            for(int j = 0;j<=k;j++){
                if(j == k && i == n)
                    dp[j] = 1;
                
                else if(i == n)
                    dp[j] = 0;
                
                else if(j + nums[i] > k || j+nums[i]<0)
                    dp[j] = dp[j];
                else
                    dp[j] = dp[j+nums[i]] + dp[j];
                
            }
        }

        return dp[0];
    }
};