////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 85. Maximal Rectangle
// Difficulty : Hard
// Link       : https://leetcode.com/problems/maximal-rectangle/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: histogram, stack-based area calculation | Time: O(m*n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 4 ms  |  Memory: 17.3 MB
// Date       : 2026-07-22
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int Max = 0;
        vector<int> heights(n,0);
        stack<int> stk;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == '1')
                    heights[j]++;
                else 
                    heights[j] = 0;
            }


            for(int j = 0;j<=n;j++){
                while(!stk.empty() && (j == n || heights[stk.top()] >= heights[j])){
                    int h = heights[stk.top()];
                    stk.pop();
                    int width = stk.empty() ? j : j - stk.top() - 1;
                    Max = max(Max,h*width);
                }
                stk.push(j);
            }

            while(!stk.empty())
                stk.pop();
            
        }


        return Max;
    }
};