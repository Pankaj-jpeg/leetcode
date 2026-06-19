////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 796. Rotate String
// Difficulty : Easy
// Link       : https://leetcode.com/problems/rotate-string/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: brute force, shifting string | Time: O(n^2) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.5 MB
// Date       : 2026-06-13
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string fun(string s){
        char first = s[0];
        s.erase(0,1);
        s.push_back(first);
        return s;
    }
    bool rotateString(string s, string goal) {
        int shift = 1;
        while(shift <= s.length()){
            s = fun(s);
            if(goal == s)
                return true;
            else{
                shift++;
            }
                
        }
        return false;
    }
};