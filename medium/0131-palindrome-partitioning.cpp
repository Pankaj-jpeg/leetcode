////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 131. Palindrome Partitioning
// Difficulty : Medium
// Link       : https://leetcode.com/problems/palindrome-partitioning/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: backtracking with palindrome check | Time: O(2^n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 35 ms  |  Memory: 53.3 MB
// Date       : 2026-07-17
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isPalindrome(string& s){
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void recur(vector<vector<string>>& res,vector<string>& part,string& curr,string& s,int idx){
        if(idx == s.size()){
            res.push_back(part);
            return;
        }

        for(int i = idx;i<s.size();i++){
            curr.push_back(s[i]);
            bool flag = isPalindrome(curr);
            if(flag){
                part.push_back(curr);
                string temp = curr;
                curr = "";
                recur(res,part,curr,s,i+1);
                part.pop_back();
                curr = temp;
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        string curr;
        recur(res,part,curr,s,0);
        return res;
    }
};