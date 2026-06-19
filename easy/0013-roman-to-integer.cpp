////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 13. Roman to Integer
// Difficulty : Easy
// Link       : https://leetcode.com/problems/roman-to-integer/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: manual case handling for each Roman numeral | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 9.9 MB
// Date       : 2026-06-13
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int romanToInt(string s) {
        int i=0;int num =0 ;
        while(i<s.length()){
            if(s[i] == 'C'){
                if(s[i+1] == 'D'){
                    num+=400;
                    i+=2;
                    continue;
                }
                else if(s[i+1] == 'M'){
                    num+=900;
                    i+=2;
                    continue;
                }
                else{
                    num+=100;
                }
            }
            if(s[i] == 'X'){
                if(s[i+1] == 'L'){
                    num+=40;
                    i+=2;
                    continue;
                }
                else if(s[i+1] == 'C'){
                    num+=90;
                    i+=2;
                    continue;
                }
                else{
                    num+=10;
                }
            }
            if(s[i] == 'I'){
                if(s[i+1] == 'V'){
                    num+=4;
                    i+=2;
                    continue;
                }
                else if(s[i+1] == 'X'){
                    num+=9;
                    i+=2;
                    continue;
                }
                else{
                    num+=1;
                }
            }
            if(s[i] == 'V')
                num+=5;
            if(s[i] == 'L')
                num+=50;
            if(s[i] == 'D')
                num+=500;
            if(s[i] == 'M')
                num+=1000;

            i++;

        }
        return num;
    }
};