////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 37. Sudoku Solver
// Difficulty : Hard
// Link       : https://leetcode.com/problems/sudoku-solver/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: backtracking | Time: O(9^(9*9/9)) | Space: O(9*9))
// Time       : 
// Space      : 
// Runtime    : 90 ms  |  Memory: 9 MB
// Date       : 2026-06-22
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool recursive(vector<vector<char>>& board,int row,int col,vector<vector<bool>>& ROW,vector<vector<bool>>& COL,vector<vector<bool>>& BOX){
        if(row == 9)
            return true;
        if(col == 9)
            return recursive(board,row+1,0,ROW,COL,BOX);

        bool found = false;
        
        if(board[row][col]  != '.'){
            return recursive(board,row,col+1,ROW,COL,BOX);
        }
        for(int i = 1;i<=9;i++){
            if(!ROW[row][i] && !COL[col][i] && !BOX[(row/3)*3 + col/3][i]){
                board[row][col] = '0' + i;
                ROW[row][i] = true;
                COL[col][i] = true;
                BOX[(row/3)*3 + col/3][i] = true;
                found = recursive(board,row,col+1,ROW,COL,BOX);
                if(found) return true;
                ROW[row][i] = false;
                COL[col][i] = false;
                BOX[(row/3)*3 + col/3][i] = false;
                board[row][col] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(10,false));
        vector<vector<bool>> col(9,vector<bool>(10,false));
        vector<vector<bool>> box(9,vector<bool>(10,false));

        for(int i = 0;i< 9;i++){
            for(int j = 0 ;j<9;j++){
                if(board[i][j]!='.'){
                    row[i][board[i][j]-'0'] = true;
                    col[j][board[i][j]-'0'] = true;
                    box[(i/3)*3 + j/3][board[i][j]-'0'] = true;
                }
            }
        }

        recursive(board,0,0,row,col,box);
    }
};