////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 55. Jump Game
// Difficulty : Medium
// Link       : https://leetcode.com/problems/jump-game/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: greedy, keep track of maximum reachable index | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 52.5 MB
// Date       : 2026-07-08
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //we check for zeroes

        int n = nums.size();
        int Max = 0;
        for(int i = 0;i<n;i++){
            if(i != n-1 && nums[i] == 0){
                if(Max <= i){
                    return false;
                }
            }

            Max = max(Max,nums[i]+i);
        }

        return true;
    }
};