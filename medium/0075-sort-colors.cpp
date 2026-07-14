////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 75. Sort Colors
// Difficulty : Medium
// Link       : https://leetcode.com/problems/sort-colors/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Dutch National Flag algorithm | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 11.8 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int a = 0;
        int b = n-1;
        int i = 0;

        while(i<=b){
            if(i < a){
                i = a;
                continue;
            }
            if(nums[i] == 0){
                swap(nums[a++],nums[i]);
            }
            else if(nums[i] == 2){
                swap(nums[b--],nums[i]);
            }
            else{
                i++;
            }
        }
        
    }
};