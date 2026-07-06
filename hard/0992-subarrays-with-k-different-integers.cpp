////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 992. Subarrays with K Different Integers
// Difficulty : Hard
// Link       : https://leetcode.com/problems/subarrays-with-k-different-integers/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: sliding window, maintain distinct count | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 8 ms  |  Memory: 44.1 MB
// Date       : 2026-07-06
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int atMost(vector<int>& nums,int k){
        if(k<0) return 0;
        
        int dis = 0;
        int l = 0;
        int cnt = 0;
        int n = nums.size();
        vector<int> m(n+1,0);
        for(int r = 0;r<n;r++){
            if(m[nums[r]] == 0){
                dis++;
            }
            m[nums[r]]++;
            while(dis > k){
                m[nums[l]]--;
                if(m[nums[l]] == 0)
                   dis--;
                l++;
            }
            cnt+=(r-l+1);
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};