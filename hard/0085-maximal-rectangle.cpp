////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 85. Maximal Rectangle
// Difficulty : Hard
// Link       : https://leetcode.com/problems/maximal-rectangle/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: histogram, stack-based area calculation | Time: O(n*m) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 1 ms  |  Memory: 17.4 MB
// Date       : 2026-07-02
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>heights(matrix[0].size(),0);
        stack<int,vector<int>> stk;
        int Max = 0;
        for(int i = 0;i<matrix.size();i++){
            int h;
            for(int j = 0;j<=matrix[0].size();j++){
                if(j == matrix[0].size())
                    h = 0;
                else{
                    if((matrix[i][j]-'0') == 0)
                        heights[j] = 0;
                    else
                        heights[j]++;
                    
                    h = heights[j];
                }

                while(!stk.empty() && heights[stk.top()] >= h){
                    int height = heights[stk.top()];
                    stk.pop();
                    int width = stk.empty() ? j : j - stk.top() - 1;
                    Max = max(Max,height*width);
                }

                stk.push(j);

            }

            while(!stk.empty())
                stk.pop();
        }
        return Max;
    }
};