////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1091. Shortest Path in Binary Matrix
// Difficulty : Medium
// Link       : https://leetcode.com/problems/shortest-path-in-binary-matrix/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Breadth-First Search (BFS) | Time: O(n^2) | Space: O(n^2))
// Time       : 
// Space      : 
// Runtime    : 5 ms  |  Memory: 23.5 MB
// Date       : 2026-08-13
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        if(grid[0][0] == 0)
            q.push({0,0});
        grid[0][0] = 1;
        int path = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                pair<int,int> cor = q.front();
                q.pop();
                int x = cor.first;
                int y = cor.second;
                if(x == n-1 && y == n-1)
                    return path;
                //top
                if(x>0 && grid[x-1][y] == 0){
                    q.push({x-1,y});
                    grid[x-1][y] = 1;
                }
                //top-left
                if(x>0 && y>0 && grid[x-1][y-1] == 0){
                    q.push({x-1,y-1});
                    grid[x-1][y-1] = 1;
                }
                //top-right
                if(x>0 && y<n-1 && grid[x-1][y+1] == 0){
                    q.push({x-1,y+1});
                    grid[x-1][y+1] = 1;
                }
                //left
                if(y>0 && grid[x][y-1] == 0){
                    q.push({x,y-1});
                    grid[x][y-1] = 1;
                }
                //right
                if(y<n-1 && grid[x][y+1] == 0){
                    q.push({x,y+1});
                    grid[x][y+1] = 1;
                }
                //down-left
                if(x<n-1 && y>0 && grid[x+1][y-1] == 0){
                    q.push({x+1,y-1});
                    grid[x+1][y-1] = 1;
                }
                //down
                if(x<n-1 && grid[x+1][y] == 0){
                    q.push({x+1,y});
                    grid[x+1][y] = 1;
                }
                //down-right
                if(x<n-1 && y<n-1 && grid[x+1][y+1] == 0){
                    q.push({x+1,y+1});
                    grid[x+1][y+1] = 1;
                }
            }
            path++;
        }
        return -1;
    }
};