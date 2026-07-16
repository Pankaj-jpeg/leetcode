////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 205. Isomorphic Strings
// Difficulty : Easy
// Link       : https://leetcode.com/problems/isomorphic-strings/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-way mapping using unordered maps | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 1 ms  |  Memory: 9.4 MB
// Date       : 2026-07-16
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> forw;
        unordered_map<char,char> back;
        int m = s.length();
        int n = t.length();

        if(m!=n)
            return false;
        
        for(int i = 0;i<m;i++){
            if(!forw.contains(s[i]) && !back.contains(t[i])){
                forw[s[i]] = t[i];
                back[t[i]] = s[i];
            }
            else
                if(t[i] != forw[s[i]] || s[i] != back[t[i]])
                    return false;
        }


        return true;
    }
};