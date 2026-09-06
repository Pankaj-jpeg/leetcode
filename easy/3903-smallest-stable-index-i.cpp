////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3903. Smallest Stable Index I
// Difficulty : Easy
// Link       : https://leetcode.com/problems/smallest-stable-index-i/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 31 MB
// Date       : 2026-09-05
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> stable(n,0);
        int Max = nums[0];
        for(int i = 0;i<n;i++){
            Max = max(Max,nums[i]);
            stable[i] += Max;
        }
        int Min = nums[n-1];
        int ans =-1;
        for(int i = n-1;i>=0;i--){
            Min = min(Min,nums[i]);
            stable[i] -= Min;
            if(stable[i] <= k)
                ans = i;
        }
        return ans; 
    }
};