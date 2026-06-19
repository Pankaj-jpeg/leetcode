////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1011. Capacity To Ship Packages Within D Days
// Difficulty : Medium
// Link       : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 11 ms  |  Memory: 35 MB
// Date       : 2026-06-10
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:

    bool feasible(int mid,vector<int>& weights,int days){
        int sum=0;int days_taken = 1;
        int i=0;
        while(i<weights.size()){
            if(sum+weights[i] <= mid){
                sum+=weights[i];
                i++;
            }
            else{
                days_taken++;
                sum=0;
            }

        }
        return days_taken <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = 0;
        for(auto weight : weights){
            high+=weight;
        }
        int mid;
        while(low<high){
            mid = low + (high-low)/2;
            if(feasible(mid,weights,days))
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};