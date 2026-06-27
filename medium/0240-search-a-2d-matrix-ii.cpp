////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 240. Search a 2D Matrix II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/search-a-2d-matrix-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search with row and column pointers | Time: O(m+n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 44 ms  |  Memory: 18.7 MB
// Date       : 2026-06-27
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n=matrix[0].size();
        int r = 0;
        int c = n-1;

        while(r < matrix.size() && c>=0){
            if(matrix[r][c] == target)
                return true;
            else if (matrix[r][c] > target)
                c--;
            else
                r++;
        }

        return false;
    }   
};