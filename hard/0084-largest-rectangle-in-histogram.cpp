////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 84. Largest Rectangle in Histogram
// Difficulty : Hard
// Link       : https://leetcode.com/problems/largest-rectangle-in-histogram/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two passes, first from right to left to find R[i] and then from left to right to find L[i] | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 11 ms  |  Memory: 88.9 MB
// Date       : 2026-07-01
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> L(n,0);
        vector<int> R(n,0);
        stack<int,vector<int>> stk;

        for(int i = n-1;i>=0;i--){
            while(!stk.empty() && heights[i] < heights[stk.top()])
                stk.pop();
            
            if(!stk.empty())
                R[i] = stk.top() - i - 1;
            else    
                R[i] = n- i -1;
            stk.push(i);
        }

        while(!stk.empty())
            stk.pop();
        
        for(int i = 0;i<n;i++){
            while(!stk.empty() && heights[i] <= heights[stk.top()])
                stk.pop();
            
            if(!stk.empty())
                L[i] = i - stk.top() - 1;
            else
                L[i] = i;
            
            stk.push(i);
        }

        
        int Max = 0;
        for(int i =0 ;i<n;i++){
            Max = max(Max,heights[i]*(L[i]+R[i]+1));
        }

        return Max;
    }
};