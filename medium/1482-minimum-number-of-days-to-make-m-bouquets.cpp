////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1482. Minimum Number of Days to Make m Bouquets
// Difficulty : Medium
// Link       : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(n log n) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 19 ms  |  Memory: 70.6 MB
// Date       : 2026-06-10
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool feasible(int mid,vector<int>& bloomDay , int m,int k){
        int k_def = k;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= mid)
                k--;
            else
                k = k_def;
            if(k==0){
                m--;
                k = k_def;
            }
            if(m==0)
                return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size())
            return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int mid;
        
        while(low<high){
            mid = low + (high-low)/2;
            if(feasible(mid,bloomDay,m,k))
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};