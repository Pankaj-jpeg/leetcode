////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 118. Pascal's Triangle
// Difficulty : Easy
// Link       : https://leetcode.com/problems/pascals-triangle/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming | Time: O(n^2) | Space: O(n^2)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 9.7 MB
// Date       : 2026-05-26
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);

        for (int i = 0; i < numRows; i++) {
           
            res[i].resize(i + 1);
            
            res[i][0] = res[i][i] = 1;
            
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        
        return res;
    }
};