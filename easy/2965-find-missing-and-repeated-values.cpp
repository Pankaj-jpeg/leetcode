////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2965. Find Missing and Repeated Values
// Difficulty : Easy
// Link       : https://leetcode.com/problems/find-missing-and-repeated-values/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: bitwise XOR | Time: O(n^2) | Space: O(n^2))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 26.8 MB
// Date       : 2026-06-25
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& nums) {
        int repeating;int n = nums.size();int k = 0;int x = 0;int itr = 1;
        vector<int> hash(n*n,0);
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                x^=nums[i][j];
                k^=itr;itr++;
                if(hash[nums[i][j]-1] == 1)
                    repeating = nums[i][j];
                else
                    hash[nums[i][j]-1] =1;
            }
        }
        x^=repeating;
        int missing = k ^ x;;
        return {repeating,missing};
    }
};