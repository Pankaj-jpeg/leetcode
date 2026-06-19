////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 410. Split Array Largest Sum
// Difficulty : Hard
// Link       : https://leetcode.com/problems/split-array-largest-sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 10.6 MB
// Date       : 2026-06-11
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool feasible(int mid,vector<int>& nums,int k){
        int sum =0;int cnt=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                sum = nums[i];
                cnt++;
                if(cnt>k) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = 0;
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
        }
        int mid;
        while(low<high){
            mid = low + (high-low)/2;
            if(feasible(mid,nums,k))
                high = mid;
            else
                low = mid+1;
        }
        return low;

    }
};