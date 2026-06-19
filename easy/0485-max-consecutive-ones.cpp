////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 485. Max Consecutive Ones
// Difficulty : Easy
// Link       : https://leetcode.com/problems/max-consecutive-ones/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: single pass, reset counter on zero | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 4 ms  |  Memory: 50.1 MB
// Date       : 2026-05-24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=0;int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                temp++;
            }
            if(nums[i]==0){
                if(temp>n)
                    n = temp;
                temp = 0;
            }
        }
        if(temp > n){
                n = temp;
        }
        return n;
    }
};