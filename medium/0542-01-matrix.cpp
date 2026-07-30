////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 542. 01 Matrix
// Difficulty : Medium
// Link       : https://leetcode.com/problems/01-matrix/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: BFS with visited matrix | Time: O(m*n) | Space: O(m*n)
// Time       : 
// Space      : 
// Runtime    : 21 ms  |  Memory: 38.9 MB
// Date       : 2026-07-30
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> res(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!mat[i][j]){
                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            for(int k = 0;k<size;k++){
                int r = q.front().second.first;
                int c = q.front().second.second;
                int d = q.front().first;
                q.pop();
                if(mat[r][c])
                    res[r][c] = d;
                if(r>0 && !vis[r-1][c]){
                    q.push({d+1,{r-1,c}});
                    vis[r-1][c] = 1;
                }

                if(r<m-1 && !vis[r+1][c]){
                    q.push({d+1,{r+1,c}});
                    vis[r+1][c] = 1;
                }

                if(c>0 && !vis[r][c-1]){
                    q.push({d+1,{r,c-1}});
                    vis[r][c-1] = 1;
                }

                if(c<n-1 && !vis[r][c+1]){
                    q.push({d+1,{r,c+1}});
                    vis[r][c+1] = 1;
                }
            }
        }

        return res;
    }
};