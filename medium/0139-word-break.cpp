////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 139. Word Break
// Difficulty : Medium
// Link       : https://leetcode.com/problems/word-break/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with memoization | Time: O(n*m) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 11.9 MB
// Date       : 2026-06-21
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    unordered_map<int,bool> mem;
    bool recursive(const string& s, vector<string>& wordDict,int idx){
        if(idx == s.length()){  
            return true;
        }
        if(idx >= s.length()) return false;

        auto itr = mem.find(idx);
        if(itr!=mem.end()) return itr->second;

        bool found = false;

    
        for(auto str : wordDict){
            int len = str.length();
            if(s.substr(idx,len) == str){
                found = recursive(s,wordDict,idx+len);
                mem.insert({idx+len,found});
                if(found){ 
                    return true;
                }
            }
        }
        
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return recursive(s,wordDict,0);
    }
};