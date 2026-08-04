////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 4008. Minimum Initial Strength to Defeat All Monsters
// Difficulty : Medium
// Link       : https://leetcode.com/problems/minimum-initial-strength-to-defeat-all-monsters/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(n log m + n) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 118 ms  |  Memory: 243.4 MB
// Date       : 2026-08-01
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    struct Comp{
        bool operator()(const vector<int>& a,const vector<int>& b){
            if(a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        }
    };
    bool feasible(vector<int>& monsters,vector<long long>& bonus,long long start){
        for(int i = 0;i<monsters.size();i++){
            if((start + bonus[i]) < monsters[i])
                return false;
            else{
                start -= monsters[i];
                if(start < 0)
                    start = 0;
            }
        }

        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> bonus(n,0);
        sort(boosts.begin(),boosts.end(),Comp());
        int m = boosts.size();
        for(int i=0;i<m;i++){
            int start = boosts[i][0];
            int end = boosts[i][1];
            int bo = boosts[i][2];

            bonus[start]+=bo;
            if(end+1 < n){
                bonus[end+1] -= bo;
            }
        }

        for(int i = 1;i<n;i++){
            bonus[i] += bonus[i-1];
        }
        long long low = 0;
        long long high = 0;
        for(auto it:monsters)
            high+=it;


        long long mid;

        while(low < high){
            mid = low + (high-low)/2;
            if(feasible(monsters,bonus,mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};