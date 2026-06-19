////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 54. Spiral Matrix
// Difficulty : Medium
// Link       : https://leetcode.com/problems/spiral-matrix/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 9.4 MB
// Date       : 2026-05-26
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(),n = matrix[0].size();
        int cnt = m*n;int k=0;
        while(cnt > result.size()){
            for(int i=k;i<n-k && cnt > result.size();i++){
                result.push_back(matrix[k][i]);
            }
            for(int i=k+1;i<m-k && cnt > result.size();i++){
                result.push_back(matrix[i][n-1-k]);
            }
            for(int i=n-2-k;i>=k && cnt > result.size();i--){
                result.push_back(matrix[m-1-k][i]);
            }
            for(int i=m-2-k;i>=k+1 && cnt > result.size();i--){
                result.push_back(matrix[i][k]);
            }
            k++;
        }
        return result;
    }
};