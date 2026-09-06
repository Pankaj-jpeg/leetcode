////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3568. Minimum Moves to Clean the Classroom
// Difficulty : Medium
// Link       : https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 243 ms  |  Memory: 156.4 MB
// Date       : 2026-09-01
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    struct Node{
        int x;
        int y;
        int e;
        int moves;
        int mask;
    };
    int minMoves(vector<string>& grid, int energy) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        int start_i,start_j;
        vector<vector<int>> id(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 'S'){
                    start_i = i;
                    start_j = j;
                }
                if(grid[i][j] == 'L')
                    id[i][j] = 1 << cnt++;
            }
        }
        //cout << cnt;
        queue<Node> q;
        vector<vector<vector<int>>> vis(m,vector<vector<int>>(n,vector<int>(1 << cnt,-1)));
        q.push({start_i,start_j,energy,0,0});
        vis[start_i][start_j][0] = energy;
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            int e = q.front().e;
            int moves = q.front().moves;
            int mask = q.front().mask;
            q.pop();
            
            if(mask == (1 << cnt)-1)
                return moves;
            if(e == 0)
                continue;
            for(int d = 0;d<4;d++){
                int r = x + dr[d];
                int c = y + dc[d];
                if(r < 0 || r >= m || c < 0 || c >=n || grid[r][c] == 'X')continue;
                int curr_energy = grid[r][c] == 'R' ? energy : e-1;

                int curr_mask = mask;
                if(grid[r][c] == 'L'){
                    curr_mask |= (id[r][c]);
                }

                if(curr_energy > vis[r][c][curr_mask]){
                    q.push({r,c,curr_energy,moves+1,curr_mask});
                    vis[r][c][curr_mask] = curr_energy;
                }
            }
           
        }

        return -1;   
    }
};