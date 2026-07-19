////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3994. Minimum Adjacent Swaps to Partition Array
// Difficulty : Medium
// Link       : https://leetcode.com/problems/minimum-adjacent-swaps-to-partition-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: greedy partitioning with two pointers | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 5 ms  |  Memory: 148.9 MB
// Date       : 2026-07-18
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int X = 0;
        int Y = 0;
        int cnt = 0;
        int modulo = 1000000007;
        for(int i = 0;i<n;i++){
            if(nums[i] < a){
                cnt = (cnt+(i-X))%modulo;
                swap(nums[i],nums[X]);
                X++;
                Y++;
            }
            else if(nums[i] > b){
                continue;
            }
            else{
                cnt = (cnt+(i-Y))%modulo;
                swap(nums[i],nums[Y]);
                Y++;
            }
        }
        

        return cnt;
    }
};