////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1631. Path With Minimum Effort
// Difficulty : Medium
// Link       : https://leetcode.com/problems/path-with-minimum-effort/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search with BFS | Time: O(n*m*log(max_val)) | Space: O(n*m))
// Time       : 
// Space      : 
// Runtime    : 123 ms  |  Memory: 49.8 MB
// Date       : 2026-08-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int k){
        for(vector<int>& vec : vis){
            fill(vec.begin(),vec.end(),0);
        }
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == n-1 && y == m-1)
                return true;
            //up
            if(x>0 && vis[x-1][y]!=1 && abs(grid[x-1][y] - grid[x][y]) <= k){
                q.push({x-1,y});
                vis[x-1][y] = 1;
            }
            //down
            if(x<n-1 && vis[x+1][y]!=1 && abs(grid[x+1][y] - grid[x][y]) <= k){
                q.push({x+1,y});
                vis[x+1][y] = 1;
            }
            //left
            if(y>0 && vis[x][y-1]!=1 && abs(grid[x][y-1] - grid[x][y]) <= k){
                q.push({x,y-1});
                vis[x][y-1] = 1;
            }
            //right
            if(y<m-1 && vis[x][y+1]!=1 && abs(grid[x][y+1] - grid[x][y]) <= k){
                q.push({x,y+1});
                vis[x][y+1] = 1;
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int low = 0;
        int high = 1000000;
        int mid;
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(low < high){
            mid = low + (high-low)/2;
            if(bfs(grid,vis,mid))
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};