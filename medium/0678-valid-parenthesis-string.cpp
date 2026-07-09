////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 678. Valid Parenthesis String
// Difficulty : Medium
// Link       : https://leetcode.com/problems/valid-parenthesis-string/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer tracking minimum and maximum possible open parentheses | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.1 MB
// Date       : 2026-07-08
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        int Min = 0;
        int Max = 0;

        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                Min++;
                Max++;
            }
            else if (s[i] == '*'){
                Min--;
                Max++;
            }
            else{
                Min--;
                Max--;
            }
            if(Max<0) return false;
            Min = max(Min,0);
        }

        return Min == 0; 
       
    }
};