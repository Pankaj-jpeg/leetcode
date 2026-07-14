////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2965. Find Missing and Repeated Values
// Difficulty : Easy
// Link       : https://leetcode.com/problems/find-missing-and-repeated-values/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: mathematical derivation of missing and repeated values | Time: O(n^2) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 4 ms  |  Memory: 25.7 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sq_sum = 0;
        long long actual_sq_sum = 0;
        int sum = 0;
        int actual_sum = 0;
        int n = grid.size();
        int itr = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                actual_sum += itr;
                sum+=(grid[i][j]);
                actual_sq_sum += (itr)*(itr);
                sq_sum += (grid[i][j])*grid[i][j];
                itr++;
            }
        }
        int a;
        int b;

        int sub = sum - actual_sum;
        int add = (sq_sum - actual_sq_sum)/sub;

        a = (sub+add)/2;
        b = add - a;
        
        return {a,b};
    }
};