////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 20. Valid Parentheses
// Difficulty : Easy
// Link       : https://leetcode.com/problems/valid-parentheses/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: stack-based matching | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 9 MB
// Date       : 2026-01-09
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isValid(string s) {
        int i=0; map<char,char> mp = {{'{','}'},{'(',')'},{'[',']'}};
        stack<char> stk;
        while(s[i]!='\0'){
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()){return false;}
                else{
                    char temp = stk.top();
                    if(mp[temp] == s[i] && !(stk.empty())){
                        stk.pop();
                    }
                    else{return false;}
                }
            }
            i++;
        }
        if(!(stk.empty())) {return false;}
        return true;
    }
};