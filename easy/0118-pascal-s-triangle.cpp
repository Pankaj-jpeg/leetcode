////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 118. Pascal's Triangle
// Difficulty : Easy
// Link       : https://leetcode.com/problems/pascals-triangle/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming | Time: O(n^2) | Space: O(n^2))
// Time       : 
// Space      : 
// Runtime    : 2 ms  |  Memory: 9.8 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        
        for(int i = 1;i<numRows;i++){
            vector<int> curr;
            for(int j = 0;j<i+1;j++){
                if(j == 0 || j == i)
                    curr.push_back(1);
                else{
                    curr.push_back(res[i-1][j-1] + res[i-1][j]);
                }
            }
            res.push_back(curr);
        }

        return res;
    }
};