////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3612. Process String with Special Operations I
// Difficulty : Medium
// Link       : https://leetcode.com/problems/process-string-with-special-operations-i/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: iterative string manipulation with special operations | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 6 ms  |  Memory: 39.8 MB
// Date       : 2026-06-16
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string_view>
class Solution {
public:
    string processStr(string s) {
        string res="";bool inverted = false;bool ifinverted = false;

        for(int i=0;i<s.length();i++){
            if(s[i]<=122 && s[i]>=97){
                if(inverted){
                    res.insert(0,1,s[i]);
                }
                else
                    res.push_back(s[i]);
            }
            else if(s[i] == '*'){
                if(res.length()>0){
                    if(inverted)
                        res.erase(0,1);
                    else
                        res.pop_back();
                }
            }
            else if(s[i] == '#'){
                res.append(res);
            }
            else{
                ifinverted = true;
                inverted = !inverted;
            }
        }
        if(inverted)
            reverse(res.begin(),res.end());
        return res;
    }
};