////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 410. Split Array Largest Sum
// Difficulty : Hard
// Link       : https://leetcode.com/problems/split-array-largest-sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 10.4 MB
// Date       : 2026-07-15
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool feasible(vector<int>& nums,int mid, int k){
        int n = nums.size();
        int arrs = 1;
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            if(sum>mid){
                arrs++;
                sum = nums[i];
            }
        }

        return arrs<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = 0;
        for(auto it : nums)
            high+=it;

        int mid;
        while(low<high){
            mid = low + (high-low)/2;
            if(feasible(nums,mid,k))
                high = mid;
            else
                low = mid+1;
        }

        return low;
    }
};