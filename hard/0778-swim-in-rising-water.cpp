////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 778. Swim in Rising Water
// Difficulty : Hard
// Link       : https://leetcode.com/problems/swim-in-rising-water/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 4 ms  |  Memory: 14 MB
// Date       : 2026-08-23
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool feasible(vector<vector<int>>& grid,int k){
        int n = grid.size();
        queue<pair<int,int>> q;
        if(grid[0][0] <= k){
            q.push({0,0});
            grid[0][0] = -1;
        }
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(r == n-1 && c == n-1)
                return true;
            

            //up
            if(r>0 && grid[r-1][c] <= k && grid[r-1][c] != -1){
                q.push({r-1,c});
                grid[r-1][c] = -1;
            }
            //down
            if(r<n-1 && grid[r+1][c] <= k && grid[r+1][c] != -1){
                q.push({r+1,c});
                grid[r+1][c] = -1;
            }
            //left
            if(c>0 && grid[r][c-1] <= k && grid[r][c-1] != -1){
                q.push({r,c-1});
                grid[r][c-1] = -1;
            }
            //right
            if(c<n-1 && grid[r][c+1] <= k && grid[r][c+1] != -1){
                q.push({r,c+1});
                grid[r][c+1] = -1;
            }

            
        }

        return false;
    }
    void reset(vector<vector<int>>& grid,vector<vector<int>>& grid_cpy){
        int n = grid.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                grid[i][j] = grid_cpy[i][j];
            }
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0;
        int high;
        vector<vector<int>> grid_cpy(n,vector<int>(n,-1));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                high = max(high,grid[i][j]);
                grid_cpy[i][j] = grid[i][j];
            }
        }

        int mid;
        
        while(low<high){
            mid = low + (high-low)/2;

            if(feasible(grid,mid))
                high = mid;
            else
                low = mid+1;

            reset(grid,grid_cpy);
        }

        return low;
    }
};