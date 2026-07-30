////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 130. Surrounded Regions
// Difficulty : Medium
// Link       : https://leetcode.com/problems/surrounded-regions/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: depth-first search (DFS) with boundary traversal | Time: O(m*n) | Space: O(m*n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 14.1 MB
// Date       : 2026-07-30
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void dfs(vector<vector<char>>& board,int r,int c){
        if(r < 0 || r > board.size()-1 || c < 0 || c > board[0].size()-1 || board[r][c] != 'O'){
            return;
        }
        board[r][c]= '#';
        dfs(board,r-1,c);
        dfs(board,r+1,c);
        dfs(board,r,c-1);
        dfs(board,r,c+1);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i<m;i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0);
            }  
            if(board[i][n-1] == 'O')
                dfs(board,i,n-1);
        }
        for(int j = 0;j<n;j++){
            if(board[0][j] == 'O'){
                dfs(board,0,j);
            }
            if(board[m-1][j] == 'O')
                dfs(board,m-1,j);
        }

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == 'O')board[i][j] = 'X';
                else if(board[i][j] == '#')board[i][j] = 'O';
            }
        }

    }
};