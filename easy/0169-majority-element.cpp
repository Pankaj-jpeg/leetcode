////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 169. Majority Element
// Difficulty : Easy
// Link       : https://leetcode.com/problems/majority-element/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Boyer-Moore Voting Algorithm | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 28.3 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0];
        int k = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == ele)
                k++;
            else{
                k--;
            }

            if(k<0){
                k = 0;
                ele = nums[i];
            }
        }

        return ele;
    }
};