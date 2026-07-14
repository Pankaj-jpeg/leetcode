////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 54. Spiral Matrix
// Difficulty : Medium
// Link       : https://leetcode.com/problems/spiral-matrix/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: iterative, boundary tracking | Time: O(m*n) | Space: O(m*n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 9.4 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up ,down ,right, left;
        up = -1;
        down = m;
        right = n;
        left = -1;

        vector<int> sp_order;

        while(sp_order.size()<m*n){
            for(int i = left+1;i<right;i++){
                sp_order.push_back(matrix[up+1][i]);
            }
            up++;
            for(int i = up+1;i<down;i++){
                sp_order.push_back(matrix[i][right-1]);
            }
            right--;
            for(int i = right-1;i>left;i--){
                sp_order.push_back(matrix[down-1][i]);
            }
            down--;
            for(int i = down-1;i>up;i--){
                sp_order.push_back(matrix[i][left+1]);
            }
            left++;
        }
        sp_order.resize(m*n);

        return sp_order;



    }
};