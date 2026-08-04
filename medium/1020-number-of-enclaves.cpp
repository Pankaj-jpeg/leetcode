////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1020. Number of Enclaves
// Difficulty : Medium
// Link       : https://leetcode.com/problems/number-of-enclaves/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: depth-first search (DFS) to mark and count enclaves | Time: O(m*n) | Space: O(m*n)
// Time       : 
// Space      : 
// Runtime    : 7 ms  |  Memory: 34.9 MB
// Date       : 2026-08-03
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    void dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]!=1)
            return;
        grid[r][c] = 2;
        dfs(grid,r-1,c);
        dfs(grid,r+1,c);
        dfs(grid,r,c-1);
        dfs(grid,r,c+1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m =  grid.size();
        int n = grid[0].size();

        for(int i = 0;i<m;i++){
            if(grid[i][n-1])
                dfs(grid,i,n-1);
            if(grid[i][0])
                dfs(grid,i,0);
        }


        for(int i = 0;i<n;i++){
            if(grid[0][i])
                dfs(grid,0,i);
            if(grid[m-1][i])
                dfs(grid,m-1,i);
        }

        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
                else
                    continue;
            }
        }
        return cnt;
    }
};