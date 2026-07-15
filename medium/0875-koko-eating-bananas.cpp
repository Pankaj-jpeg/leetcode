////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 875. Koko Eating Bananas
// Difficulty : Medium
// Link       : https://leetcode.com/problems/koko-eating-bananas/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(n log max(piles)) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 8 ms  |  Memory: 22.9 MB
// Date       : 2026-07-15
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool feasible(vector<int>& piles,int mid,int h){
        int time = 0;
        int n = piles.size();
        int i = 0;
        while(i<n){
            if(piles[i] <= mid){
                time++;
            }
            else{
                if(piles[i]%mid == 0)
                    time+=(piles[i]/mid);
                else
                    time+=(piles[i]/mid) + 1;
            }
            i++;
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int mid;
        while(low<high){
            mid = low + (high-low)/2;
            if(feasible(piles,mid,h))
                high = mid;
            else    
                low = mid+1;
        }   

        return low;
    }
};