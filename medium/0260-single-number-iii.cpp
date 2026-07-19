////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 260. Single Number III
// Difficulty : Medium
// Link       : https://leetcode.com/problems/single-number-iii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: bitwise manipulation, finding the rightmost set bit | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 13.9 MB
// Date       : 2026-07-19
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor = 0;

        for(int i = 0;i<nums.size();i++){
           Xor = (Xor^nums[i]);
        }

        int q = 1;
        while(true){
            if(Xor & q) break;
            q = (q << 1);
        }
        int n = nums.size();
        int a = 0;
        for(int i = 0;i<n;i++){
            if((nums[i]&q) == 0){
                a = (a^nums[i]);
            }
        }

        int b = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]&q){
                b = (b^nums[i]);
            }
        }
        return {a,b};
    }
};