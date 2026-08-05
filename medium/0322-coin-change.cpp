////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 322. Coin Change
// Difficulty : Medium
// Link       : https://leetcode.com/problems/coin-change/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with bottom-up approach | Time: O(n*amount) | Space: O(amount))
// Time       : 
// Space      : 
// Runtime    : 36 ms  |  Memory: 17.8 MB
// Date       : 2026-08-05
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
   
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,-2);
        
        for(int i = n;i>=0;i--){
            for(int j = 0;j<=amount;j++){
                if(j==0)
                    dp[j] = 0;
                else if(i == n){
                    dp[j] = -1;
                }
                else if(j-coins[i] < 0)
                    dp[j] = dp[j];
                else{
                    if(dp[j-coins[i]]==-1 && dp[j]==-1)
                        dp[j] = -1;
                    else if(dp[j-coins[i]] == -1)
                        dp[j] = dp[j];
                    else if(dp[j] == -1)
                        dp[j] = 1+dp[j-coins[i]];
                    else
                        dp[j] = min(1+dp[j-coins[i]],dp[j]);
                }
            }
        }

        return dp[amount];
    }
};