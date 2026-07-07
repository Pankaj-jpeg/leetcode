////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 76. Minimum Window Substring
// Difficulty : Hard
// Link       : https://leetcode.com/problems/minimum-window-substring/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: sliding window, maintain a count of required characters | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 4 ms  |  Memory: 11.4 MB
// Date       : 2026-07-07
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128,-1);
        for(int i = 0;i<t.size();i++){
            if(m[t[i]] == -1)
                m[t[i]] = 0;
            m[t[i]]++;
        }
        int l = 0;
        int unsat = t.size();
        int n = s.size();
        int Min = INT_MAX;
        int head=0;
        for(int r = 0;r<n;r++){
            m[s[r]]--;
            if(m[s[r]] >= 0)
                unsat--;
        
            while(unsat == 0){
                if(Min > (r-l+1)){
                    head = l;
                    Min = r-l+1;
                }
                m[s[l]]++;
                if(m[s[l]] == 1){
                    unsat++;
                }
                l++;
            }


        }
        return Min == INT_MAX ? "" : s.substr(head,Min);
    }
};