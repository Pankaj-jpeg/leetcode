////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 169. Majority Element
// Difficulty : Easy
// Link       : https://leetcode.com/problems/majority-element/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Boyer-Moore Voting Algorithm | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 28.2 MB
// Date       : 2026-05-24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,ele;

        for(int i=0;i<nums.size();i++){
            if(count==0){
                count++;
                ele=nums[i];
            }
            else if(ele!=nums[i])
                count--;
            else
                count++;
        }
        return ele;
    }
};