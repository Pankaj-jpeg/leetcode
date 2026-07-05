////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1004. Max Consecutive Ones III
// Difficulty : Medium
// Link       : https://leetcode.com/problems/max-consecutive-ones-iii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique with dynamic adjustment | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 69.6 MB
// Date       : 2026-07-05
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int zeroes = 0;
        int Max = 0;
        
        while(r<n){
            if(nums[r] == 0){
                if(k == 0){
                    r++;
                    l=r;
                    continue;
                }
                else if(zeroes < k){
                    zeroes++;
                }
                else{
                    while(zeroes==k){
                        if(nums[l] == 0){
                            zeroes--;
                        }
                        l++;
                    }
                    zeroes++;
                }
            }
            Max = max(Max,r - l + 1);
            r++;         
        }

        return Max;
    }
};