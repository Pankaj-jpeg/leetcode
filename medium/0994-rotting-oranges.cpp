////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 994. Rotting Oranges
// Difficulty : Medium
// Link       : https://leetcode.com/problems/rotting-oranges/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Breadth-First Search (BFS) using a queue | Time: O(m*n) | Space: O(m*n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 16.7 MB
// Date       : 2026-07-28
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        if(i >= 0 && i<m && j>=0 && j<n)
            return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        int cnt=0;
        while(!q.empty()){
            int size = q.size();
            
            for(int k = 0;k<size;k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                //up
                if(isValid(i-1,j,m,n) && grid[i-1][j]==1){
                    q.push({i-1,j});
                    grid[i-1][j] = 2;
                }

                //down
                if(isValid(i+1,j,m,n) && grid[i+1][j]==1){
                    q.push({i+1,j});
                    grid[i+1][j] = 2;
                }

                //right
                if(isValid(i,j+1,m,n) && grid[i][j+1]==1){
                    q.push({i,j+1});
                    grid[i][j+1] = 2;
                }


                //left
                if(isValid(i,j-1,m,n) && grid[i][j-1]==1){
                    q.push({i,j-1});
                    grid[i][j-1] = 2;
                }
                
            }
            if(q.size()>0)
                cnt++;
        }

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1)    
                    return -1;
            }
        }

        return cnt;
    }
};