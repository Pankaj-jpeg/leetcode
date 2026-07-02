////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 84. Largest Rectangle in Histogram
// Difficulty : Hard
// Link       : https://leetcode.com/problems/largest-rectangle-in-histogram/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: stack-based histogram scanning | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 78.6 MB
// Date       : 2026-07-02
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int,vector<int>> stk;
        int Max = 0;

        for(int i = 0;i<=n;i++){
            int h;
            if(i == n)
                h = 0;
            else
                h = heights[i]; 
            
            while(!stk.empty() && h <= heights[stk.top()]){
                int height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                Max = max(Max,width*height);
            }

            stk.push(i);

        }

        return Max;
    }
};