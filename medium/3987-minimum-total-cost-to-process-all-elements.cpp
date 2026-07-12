////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3987. Minimum Total Cost to Process All Elements
// Difficulty : Medium
// Link       : https://leetcode.com/problems/minimum-total-cost-to-process-all-elements/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 13 ms  |  Memory: 169.4 MB
// Date       : 2026-07-12
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int avail = k;
        int cost = 0;
        long long op = 0;
        long long mul;
        int temp = pow(10,9) + 7;

        for(int i = 0;i<nums.size();i++){
            if(avail>=nums[i])
                avail-=nums[i];
            else{
                mul = (nums[i] - avail)/k;
                if((nums[i]-avail)%k != 0)
                    mul++;

                avail += k*mul;
                long long total = (op+mul)%temp;
                cost = (total*(total+1))%temp * 500000004%temp;
                op += mul;
                avail -= nums[i];
            }
        }

        return cost;
        
    }
};