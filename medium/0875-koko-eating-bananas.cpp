////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 875. Koko Eating Bananas
// Difficulty : Medium
// Link       : https://leetcode.com/problems/koko-eating-bananas/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(n log max(piles)) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 2 ms  |  Memory: 23 MB
// Date       : 2026-06-10
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:

    bool feasible(int k,vector<int>& piles,int h){
        int temp=0;
        for(int i=0;i<piles.size();i++){
            temp += (piles[i]+k-1)/k;
        }
        return temp <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int mid;

        while(low<high){
            mid = low + (high-low)/2;

            if(feasible(mid , piles, h))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};