////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 200. Number of Islands
// Difficulty : Medium
// Link       : https://leetcode.com/problems/number-of-islands/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Depth-First Search (DFS) | Time: O(m*n) | Space: O(m*n)
// Time       : 
// Space      : 
// Runtime    : 25 ms  |  Memory: 16.3 MB
// Date       : 2026-08-03
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1')
            return;
        
        grid[i][j] = '#';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};