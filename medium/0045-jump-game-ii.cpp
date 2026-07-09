////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 45. Jump Game II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/jump-game-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: greedy, maintain the maximum reachable position | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 20.7 MB
// Date       : 2026-07-08
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        int cnt = 0;
        int end = 0;
        int Max = 0;
        for(int i = 0 ;i<n;i++){
            Max = max(Max,nums[i] + i);

            if(i == end){
                if(end >= n-1){
                    break;
                } 
                cnt++;
                end = Max;

               
            }
        }
        return cnt;
    }
};