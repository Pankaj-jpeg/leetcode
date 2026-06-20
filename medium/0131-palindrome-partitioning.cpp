////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 131. Palindrome Partitioning
// Difficulty : Medium
// Link       : https://leetcode.com/problems/palindrome-partitioning/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: backtracking with recursive partitioning | Time: O(2^n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 92 ms  |  Memory: 88.1 MB
// Date       : 2026-06-19
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    
    bool is_pal(string str,int start,int end){
        while(start<end){
            if(str[start]!=str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> res; vector<string> curr;
    void recursive(string s,int par_idx){
        if(par_idx == s.length()){
            res.push_back(curr);
            return;
        }
        
        for(int i = par_idx;i<s.length();i++){
            if(is_pal(s,par_idx,i)){
                string str = s.substr(par_idx,i-par_idx+1);
                curr.push_back(str);
                recursive(s,i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        recursive(s,0);
        return res;
    }
};