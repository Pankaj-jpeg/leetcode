////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 51. N-Queens
// Difficulty : Hard
// Link       : https://leetcode.com/problems/n-queens/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: backtracking with diagonal constraints | Time: O(n!) | Space: O(n^2))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 10.2 MB
// Date       : 2026-06-20
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    
    void recursive(int n,vector<vector<string>>& result,vector<string>& curr,vector<int>& row,vector<int>& diag1,vector<int>& diag2,int col){
        if(col == n){
            result.push_back(curr);
            return;
        }

        for(int i = 0;i<n;i++){
            if(row[i] || diag1[i+col] || diag2[i-col+n]) continue;

            curr[i][col] = 'Q';
            row[i] = diag1[i+col] = diag2[i-col+n] = 1;
            recursive(n,result,curr,row,diag1,diag2,col+1);
            curr[i][col] = '.';
            row[i] = diag1[i+col] = diag2[i-col+n] = 0;
            
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;vector<int> row(n,0);vector<int> diag1(2*n,0);vector<int> diag2(2*n,0);
        vector<string> curr(n, string(n, '.'));
        recursive(n,result,curr,row,diag1,diag2,0);
        return result;
    }
};