////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 721. Accounts Merge
// Difficulty : Medium
// Link       : https://leetcode.com/problems/accounts-merge/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 37 ms  |  Memory: 39.6 MB
// Date       : 2026-08-21
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
        if(ulp_x == ulp_z)return;

        if(sze[ulp_x] >= sze[ulp_z]){
            sze[ulp_x]+=sze[ulp_z];
            par[ulp_z] = ulp_x;
        }
        else{
            sze[ulp_z] += sze[ulp_x];
            par[ulp_x] = ulp_z;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {  
        int n = accounts.size();
        map<string,int> m;
        vector<int> par(n),sze(n);
        for(int i = 0;i<n;i++){
            par[i] = i;
            sze[i] = 1;
        }
        for(int i = 0;i<accounts.size();i++){
            for(int j = 1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j]) != m.end()){
                    uni(m[accounts[i][j]],i,par,sze);
                    continue;
                }

                m.insert({accounts[i][j],i});
            }
        }

        vector<vector<string>> res(n);
        for(auto it : m){
            string s = it.first;
            int key = it.second;
            int site = findPar(key,par);

            res[site].push_back(s);
        }

        vector<vector<string>> ans;

        for(int i = 0;i<n;i++){
            if(res[i].size() == 0)
                continue;
            else{
                vector<string> row;
                row.push_back(accounts[i][0]);
                //sort(res[i].begin(),res[i].end());
                for(auto it : res[i]){
                    row.push_back(it);
                }
                ans.push_back(row);
            }
        }
        return ans;

    }
};