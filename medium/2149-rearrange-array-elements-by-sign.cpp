////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2149. Rearrange Array Elements by Sign
// Difficulty : Medium
// Link       : https://leetcode.com/problems/rearrange-array-elements-by-sign/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique, alternating positive and negative numbers | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 12 ms  |  Memory: 128.3 MB
// Date       : 2026-05-25
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());int j=0;int k=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                result[j] = nums[i];
                j+=2; 
            }
            else{
                result[k] = nums[i];
                k+=2;
            }
        }
        return result;
    }
};