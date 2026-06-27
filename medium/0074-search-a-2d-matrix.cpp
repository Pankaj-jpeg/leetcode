////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 74. Search a 2D Matrix
// Difficulty : Medium
// Link       : https://leetcode.com/problems/search-a-2d-matrix/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search, divide matrix into two halves | Time: O(log(m) + log(n)) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 13.3 MB
// Date       : 2026-06-27
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();int n = matrix[0].size();
        int low = 0;
        int high = m-1;
        int mid;

        while(low<high){
            mid = low + (high-low)/2;
            if(matrix[mid][0] >= target){
                high = mid;
            }
            else
                low = mid + 1;
        }
        if(matrix[low][0] == target)
            return true;
        int row;
        if(low > 0 && matrix[low][0] > target) row = low-1;
        else row = low;
        low = 0;
        high = n-1;
        while(low<high){
            mid = low + (high-low)/2;
            if(target <= matrix[row][mid])
                high = mid;
            else
                low = mid+1;
        }
        return matrix[row][low] == target;
    }
};