////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1248. Count Number of Nice Subarrays
// Difficulty : Medium
// Link       : https://leetcode.com/problems/count-number-of-nice-subarrays/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique with prefix sum | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 16 ms  |  Memory: 71.4 MB
// Date       : 2026-07-06
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
    int atMost(vector<int>& nums,int k){
        int n = nums.size();
        int cnt = 0;
        int l = 0;
        int odd_cnt = 0;
        for(int r = 0;r<n;r++){
            if(nums[r]%2 != 0)
                odd_cnt++;
            
            while(odd_cnt > k){
                if(nums[l]%2 != 0)
                    odd_cnt--;
                l++;
            }

            cnt+=r-l+1;
        }
        return cnt;
    }
};