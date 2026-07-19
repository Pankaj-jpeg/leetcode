////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 79. Word Search
// Difficulty : Medium
// Link       : https://leetcode.com/problems/word-search/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: depth-first search with backtracking | Time: O(m*n*4^l) | Space: O(l))
// Time       : 
// Space      : 
// Runtime    : 191 ms  |  Memory: 10.4 MB
// Date       : 2026-07-17
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool recur(vector<vector<char>>& board,string& word,int r,int c,int idx){
        if(idx == word.size())
            return true;
        
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]!=word[idx])
            return false;
        
        char temp = board[r][c];
        board[r][c] = '#';
        bool found = recur(board,word,r-1,c,idx+1) || //up
        recur(board,word,r+1,c,idx+1) || //down
        recur(board,word,r,c-1,idx+1) || //left
        recur(board,word,r,c+1,idx+1);  //right

        board[r][c] = temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        if(m*n < word.size())
            return false;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(recur(board,word,i,j,0)) return true;
            }
        }

        return false;
    }
};