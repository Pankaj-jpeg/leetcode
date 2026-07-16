////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 921. Minimum Add to Make Parentheses Valid
// Difficulty : Medium
// Link       : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: stack-free, counter-based | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.3 MB
// Date       : 2026-07-16
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minAddToMakeValid(string s) {
       int cnt = 0;
       int size = 0;

        for(int i = 0;i<s.size();i++){
            if(s[i] == '(')
                size++;
            else{
                if(size == 0)
                    cnt++;
                else{
                    size--;;
                }
            }
        }

        if(size!=0)
            cnt+=size;
        
        return cnt;
    }
};