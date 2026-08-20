////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1319. Number of Operations to Make Network Connected
// Difficulty : Medium
// Link       : https://leetcode.com/problems/number-of-operations-to-make-network-connected/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 27 ms  |  Memory: 47.3 MB
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
            sze[ulp_z] += sze[ulp_x];
            par[ulp_x] = ulp_z;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()+1 < n)
            return -1;

        vector<int> par(n),sze(n);


        for(int i = 0;i<n;i++){
            par[i] = i;
            sze[i] = 1;
        }

        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            uni(u,v,par,sze);
        }
        vector<int> vis(n,0);
        int cnt = 0;
        for(int& i : par){
            int p = findPar(i,par);
            if(vis[p] == 1)
                continue;
            vis[p] = 1;
            cnt++;
        }

        return cnt-1;
       
    }
};