////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 48. Rotate Image
// Difficulty : Medium
// Link       : https://leetcode.com/problems/rotate-image/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two passes, first transpose then reverse each row | Time: O(n^2) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 10.2 MB
// Date       : 2026-05-26
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<j)
                    swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j < n/2){
                    swap(matrix[i][j],matrix[i][n-j-1]);
                }
            }
        }

    }
};