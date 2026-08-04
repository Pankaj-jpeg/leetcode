////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 416. Partition Equal Subset Sum
// Difficulty : Medium
// Link       : https://leetcode.com/problems/partition-equal-subset-sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming | Time: O(n * (sum/2)) | Space: O(sum/2))
// Time       : 
// Space      : 
// Runtime    : 79 ms  |  Memory: 14.9 MB
// Date       : 2026-08-04
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums)
            sum+=it;
        
        if(sum%2!=0)
            return false;
    
        int idx=0;
        int n = nums.size();
        vector<int> dp((sum/2)+1,-1);
        
        int S = sum/2;

        for(int i = n-1;i>=0;i--){
            for(int j = S;j>=0;j--){
                if(j == 0)
                    dp[j] = 1;
                else if(i == n-1){
                    if(j-nums[i] == 0)
                        dp[j] = 1;
                    else
                        dp[j] = 0;
                }
                else if(j-nums[i] < 0)
                    dp[j] = dp[j];
                else
                    dp[j] = dp[j] || dp[j-nums[i]];
            }
        }


        return dp[S];
    }
};