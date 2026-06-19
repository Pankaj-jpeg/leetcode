////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 205. Isomorphic Strings
// Difficulty : Easy
// Link       : https://leetcode.com/problems/isomorphic-strings/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-way mapping | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 9.5 MB
// Date       : 2026-06-13
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char,char> for_map;
        unordered_map <char,char> back_map;
        bool found_in_for;
        bool found_in_back;

        int i=0;
        while(i<s.length()){
            found_in_for = for_map.find(s[i]) != for_map.end();
            found_in_back = back_map.find(t[i]) != back_map.end();
            if(!found_in_for && !found_in_back){
                for_map.insert({s[i],t[i]});
                back_map.insert({t[i],s[i]});
            }
            else{
                if(found_in_for && for_map.find(s[i])->second != t[i] || found_in_back && back_map.find(t[i])->second != s[i])
                    return false;
            }
            i++;
        }
        return true;

    }
};