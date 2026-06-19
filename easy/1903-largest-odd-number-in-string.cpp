////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1903. Largest Odd Number in String
// Difficulty : Easy
// Link       : https://leetcode.com/problems/largest-odd-number-in-string/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: single pass, find rightmost odd digit | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 17.8 MB
// Date       : 2026-06-13
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string largestOddNumber(string num) {
        int rightmost_odd = -1;
        for(int i=0;i<num.length();i++){
            if((num[i] - '0')%2 != 0){
                rightmost_odd = i;
            }
        }
        if(rightmost_odd!=-1)
            return num.substr(0,rightmost_odd+1);
        else
            return "";
    }
};