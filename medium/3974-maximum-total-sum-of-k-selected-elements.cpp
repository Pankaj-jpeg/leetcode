////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3974. Maximum Total Sum of K Selected Elements
// Difficulty : Medium
// Link       : https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: greedy, selecting the largest elements first | Time: O(n log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 75 ms  |  Memory: 186.4 MB
// Date       : 2026-06-28
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        int cnt = 0;long long sum = 0;
        for(int i = nums.size()-1;i>=0;i--){
            if(mul>0)
                sum += (long long)mul*nums[i];
            else
                sum += nums[i];
            cnt++;
            mul--;
            if(cnt == k)break;
        }

        return sum;
    }
};