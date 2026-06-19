////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1614. Maximum Nesting Depth of the Parentheses
// Difficulty : Easy
// Link       : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: string filtering and stack simulation | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.4 MB
// Date       : 2026-06-13
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxDepth(string s) {
        string paren = "";
        for(auto it : s){
            if(it == '(' || it == ')')
                paren.push_back(it);
        }
        if(paren == ""){
            return 0;
        }
        int depth = 0;int max_depth = INT_MIN;
        for(auto it : paren){
            if(it == '(')
                depth++;
            else
                depth--;

            if(depth > max_depth)
                max_depth = depth;
        }   
        return max_depth;
    }
};