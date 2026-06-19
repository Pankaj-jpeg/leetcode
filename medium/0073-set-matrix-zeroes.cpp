////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 73. Set Matrix Zeroes
// Difficulty : Medium
// Link       : https://leetcode.com/problems/set-matrix-zeroes/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 20.6 MB
// Date       : 2026-05-26
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        int firstrowzero =0;
        int firstcolzero = 0;
        int m = nums.size(),n = nums[0].size();

        for(int i =0;i<n;i++){
            if(nums[0][i] == 0){
                firstrowzero=1;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(nums[i][0] == 0){
                firstcolzero=1;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(nums[i][j] == 0){
                    nums[0][j] = 0;
                    nums[i][0] = 0;
                }
            }
        }
        for(int i = 1;i<m;i++){
            for(int j=1;j<n;j++){
                if(nums[i][0] == 0 || nums[0][j] == 0){
                    nums[i][j]=0;
                }
            }
        }
        if(firstrowzero){
            for(int i=0;i<n;i++){
                nums[0][i]=0;
            }
        }
         if(firstcolzero){
            for(int i=0;i<m;i++){
                nums[i][0]=0;
            }
        }
    }
};