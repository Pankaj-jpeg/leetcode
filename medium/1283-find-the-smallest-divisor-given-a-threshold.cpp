////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1283. Find the Smallest Divisor Given a Threshold
// Difficulty : Medium
// Link       : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(n log m) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 4 ms  |  Memory: 26.1 MB
// Date       : 2026-06-10
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool feasible(int mid,vector<int>& nums,int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += (nums[i]+mid-1)/mid;
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int mid;
        while(low<high){
            mid = low + (high-low)/2;
            if(feasible(mid,nums,threshold))
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};