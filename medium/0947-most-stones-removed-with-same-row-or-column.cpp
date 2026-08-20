////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 947. Most Stones Removed with Same Row or Column
// Difficulty : Medium
// Link       : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 15 ms  |  Memory: 22.2 MB
// Date       : 2026-08-20
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findPar(int x,vector<int>& par){
        if(x == par[x])
            return x;
        return par[x] = findPar(par[x],par);
    }
    void uni(int x,int z,vector<int>& par,vector<int>& sze){
        int ulp_x = findPar(x,par);
        int ulp_z = findPar(z,par);
        if(ulp_x == ulp_z)
            return;
        if(sze[ulp_x] >= sze[ulp_z]){
            sze[ulp_x]+=sze[ulp_z];
            par[ulp_z] = ulp_x;
        }
        else{
            par[ulp_x] = ulp_z;
            sze[ulp_z] += sze[ulp_x];
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=0,m=0;
        for(auto it : stones){
            n = max(n,it[0]);
            m = max(m,it[1]);
        }
        vector<int> par(n+m+2),sze(n+m+2);
        for(int i = 0;i<n+m+2;i++){
            par[i] = i;
            sze[i] = 1;
        }
        int shift = n+1;
        for(auto i : stones){
            uni(i[0],i[1]+shift,par,sze);
        }
        //vector<int> vis(n+m+2,0);
        int nodes = 0;
        int cnt = 0;
        for(int i = 0;i<n+m+2;i++){
            int p = findPar(i,par);
            //cout << p << " " << sze[i] << "\n";
            if(p == i && sze[p] == 1){
                continue;
            }
            if(p == i)
                cnt++;
        }
        return stones.size()-cnt;
    }
};