////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1901. Find a Peak Element II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/find-a-peak-element-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search on each row | Time: O(m log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 50.2 MB
// Date       : 2026-06-27
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        for(int i = 0;i<mat.size();i++){
            int low = 0;
            int high = mat[0].size()-1;
            int mid;
            while(low <= high){
                mid = low + (high-low)/2;
                int up=-1,down=-1,right=-1,left=-1;

                if(i != 0)
                    up = mat[i-1][mid];
                if(i != mat.size()-1)
                    down = mat[i+1][mid];
                if(mid != 0)
                    left = mat[i][mid-1];
                if(mid != mat[0].size()-1)
                    right = mat[i][mid+1];
                
                if(mat[i][mid] > up && mat[i][mid] > down && mat[i][mid] > right && mat[i][mid] > left)
                    return {i,mid};
                else if(mat[i][mid] < left)
                    high = mid-1;
                else if(mat[i][mid] < right)
                    low = mid+1;
                else
                    break;
            }
        }
        return {0,0};
    }
};