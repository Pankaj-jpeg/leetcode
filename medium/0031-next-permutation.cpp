////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 31. Next Permutation
// Difficulty : Medium
// Link       : https://leetcode.com/problems/next-permutation/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: find the first decreasing pair and swap with the smallest larger element | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 15.6 MB
// Date       : 2026-05-25
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int just_larger;int breaking_pt = nums.size();
        for(int j=nums.size()-1;j>=0;j--){
            if(j!=nums.size()-1 && nums[j]<nums[j+1]){
                breaking_pt=j;
                break;
            }
        }

        if(breaking_pt!=nums.size()){
            for(int i=nums.size()-1;i>breaking_pt;i--){
                if(nums[i]>nums[breaking_pt]){
                    just_larger =i;
                    break;
                }
            }   

            swap(nums[just_larger],nums[breaking_pt]);
            reverse(nums.begin()+breaking_pt+1,nums.end());
        }
        else
            reverse(nums.begin(),nums.end());
    }
};