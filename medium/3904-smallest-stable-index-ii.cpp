////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3904. Smallest Stable Index II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/smallest-stable-index-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 7 ms  |  Memory: 202.5 MB
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