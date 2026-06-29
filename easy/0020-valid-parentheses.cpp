////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 20. Valid Parentheses
// Difficulty : Easy
// Link       : https://leetcode.com/problems/valid-parentheses/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: stack-based matching | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.8 MB
// Date       : 2026-06-28
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isValid(string s) {
        int i = 0;stack<char> stk;
        while(s[i]!='\0'){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stk.push(s[i]);
                i++;
            }
            else{
                if(stk.empty()) return false;
                if((s[i] == ')' && stk.top() != '(') || (s[i] == ']' && stk.top() != '[') || (s[i] == '}' && stk.top() != '{'))      
                    return false;
                else
                    stk.pop();
                i++;
            }
        }

        return stk.empty();
    }
};