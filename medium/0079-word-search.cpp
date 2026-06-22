////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 79. Word Search
// Difficulty : Medium
// Link       : https://leetcode.com/problems/word-search/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: depth-first search with backtracking | Time: O(m*n*4^l) | Space: O(l))
// Time       : 
// Space      : 
// Runtime    : 241 ms  |  Memory: 10.6 MB
// Date       : 2026-06-21
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool recursive(vector<vector<char>>& board,const string& word,int row,int col,int idx){
        if(idx == word.length()){
            return true;
        }
        if( row < 0 || row >=board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[idx] || board[row][col] == '#' ) return false;
        
        char temp = board[row][col];
        board[row][col]='#';

        //up
        bool found = recursive(board,word,row-1,col,idx+1) ||
        //down
        recursive(board,word,row+1,col,idx+1) ||
        //right
        recursive(board,word,row,col+1,idx+1) ||
        //left
        recursive(board,word,row,col-1,idx+1);

        board[row][col]=temp;
        
        return found;
    }   

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        if(m*n < word.length()) return false;

        for(int r = 0;r<m;r++){
            for(int c = 0;c<n;c++){
                if(recursive(board,word,r,c,0)) return true; 
            }
        }
        
        return false;
    }
};