////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3813. Vowel-Consonant Score
// Difficulty : Easy
// Link       : https://leetcode.com/problems/vowel-consonant-score/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: simple iteration, checking each character | Time: O(n) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 1 ms  |  Memory: 9.1 MB
// Date       : 2026-01-18
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int vowelConsonantScore(string s) {
        int i=0;int v=0;int c=0;
        while(s[i]!='\0'){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                v++;
            }
            if(s[i]=='b' || s[i]=='c' || s[i]=='d' || s[i]=='f' || s[i]=='g' || s[i]=='h' || s[i]=='j' || s[i]=='k' || s[i]=='l' || s[i]=='m' || s[i]=='n' || s[i]=='p' || s[i]=='q' || s[i]=='r' || s[i]=='s' || s[i]=='t' || s[i]=='v' || s[i]=='w' || s[i]=='x' || s[i]=='y' || s[i]=='z'){
                c++;
            }
            i++;
        }

        if(c>0)
            return v/c;
        else
            return 0;
    }
};