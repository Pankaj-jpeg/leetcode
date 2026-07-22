////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 84. Largest Rectangle in Histogram
// Difficulty : Hard
// Link       : https://leetcode.com/problems/largest-rectangle-in-histogram/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: stack-based histogram scanning | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 12 ms  |  Memory: 79.5 MB
// Date       : 2026-07-22
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();
        int Max = 0;

        for(int i = 0;i<=n;i++){
            while(!stk.empty() && (i == n || heights[stk.top()] >= heights[i])){
                int h = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i- stk.top() - 1;
                Max = max(Max,h*width); 
            }
            stk.push(i);
        }

        return Max;
    }
};