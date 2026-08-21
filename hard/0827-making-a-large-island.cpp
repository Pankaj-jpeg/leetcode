////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 827. Making A Large Island
// Difficulty : Hard
// Link       : https://leetcode.com/problems/making-a-large-island/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 64 ms  |  Memory: 60.4 MB
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
            sze[ulp_x] += sze[ulp_z];
            par[ulp_z] = ulp_x;
        }
        else{
            sze[ulp_z] += sze[ulp_x];
            par[ulp_x] = ulp_z;
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    n++;
                    grid[i][j] = n;
                }
            }
        }
        vector<int> par(n+1),sze(n+1);
        for(int i = 1;i<=n;i++){
            par[i] = i;
            sze[i] = 1;
        }
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                    int node = grid[i][j];
                    if(i > 0 && grid[i-1][j] > 0)
                        uni(grid[i-1][j],node,par,sze);
                    if(i < grid.size()-1 && grid[i+1][j] > 0)
                        uni(grid[i+1][j],node,par,sze);   
                    if(j > 0 && grid[i][j-1] > 0)
                        uni(grid[i][j-1],node,par,sze);
                    if(j < grid[0].size()-1 && grid[i][j+1] > 0)
                        uni(grid[i][j+1],node,par,sze);
                    
                }
            }
        }
        
        int Max = *max_element(sze.begin(),sze.end());
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 0){
                    int up = 0,down=0,right=0,left=0;
                    int up_par = -1,down_par = -1,left_par=-1,right_par=-1;
                    if(i>0 && grid[i-1][j]>0){
                        up_par = findPar(grid[i-1][j],par);
                        up = sze[up_par];
                    }
                    if(i<grid.size()-1 && grid[i+1][j]>0){
                        down_par = findPar(grid[i+1][j],par);
                        down = sze[down_par];
                    }
                    if(j>0 && grid[i][j-1]>0){
                        left_par = findPar(grid[i][j-1],par);
                        left = sze[left_par];
                    }
                    if(j<grid[0].size()-1 && grid[i][j+1]>0){
                        right_par = findPar(grid[i][j+1],par);
                        right = sze[right_par];
                    }
                    
                    int total_size = 0;
                    if(up_par != down_par && up_par != left_par && up_par != right_par)
                        total_size+=up;
                    if(down_par != left_par && down_par != right_par)
                        total_size+=down;
                    if(left_par != right_par)
                        total_size+=left;
                    total_size+=right;


                    Max = max(Max,1+total_size);
                }
            }
        }
        return Max;
    }
};