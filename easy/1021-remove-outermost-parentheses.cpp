////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1021. Remove Outermost Parentheses
// Difficulty : Easy
// Link       : https://leetcode.com/problems/remove-outermost-parentheses/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer, tracking parentheses count | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.9 MB
// Date       : 2026-06-12
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;int splits = 0;bool flag = true;bool add;string res = "";
        for(int i = 0;i<s.length();i++){
            add = true;
            if(flag){
                add = false;
                flag = false;
            }
            if(s[i] == '(')
                cnt++;
            if(s[i] == ')')
                cnt--;
            if(cnt == 0){
                add = false;
                splits++;
                flag = true;
            }
            if(add){
                res.push_back(s[i]);
            }
        }
        return res;
    }
};