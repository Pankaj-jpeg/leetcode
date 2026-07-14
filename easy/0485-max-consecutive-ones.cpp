////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 485. Max Consecutive Ones
// Difficulty : Easy
// Link       : https://leetcode.com/problems/max-consecutive-ones/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: single pass, reset counter on zero | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 50.1 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int Max = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 1)
                cnt++;
            else{
                Max = max(Max,cnt);
                cnt = 0;
            }
        }

        Max = max(Max,cnt);

        return Max;
    }
};