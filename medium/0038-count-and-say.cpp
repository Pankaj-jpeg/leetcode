////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 38. Count and Say
// Difficulty : Medium
// Link       : https://leetcode.com/problems/count-and-say/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: iterative, counting consecutive occurrences | Time: O(n*m) | Space: O(m))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 10.9 MB
// Date       : 2026-07-16
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:

    string RLE(string s){
        vector<int> cnts(10);
        string res="";
        int n = s.size();
        for(int i = 0;i<s.size();i++){
            cnts[s[i]-'0']++;
            if(i>0 && s[i] != s[i-1]){
                string temp = to_string(cnts[s[i-1]-'0']) + s[i-1];
                cnts[s[i-1]-'0'] = 0;
                res+=temp;
            }
        }
        string temp = to_string(cnts[s[n-1]-'0']) + s[n-1];
        res+=temp;

        return res;
    }
    string countAndSay(int n) {
        string s="1";

        while(n>1){
            s = RLE(s);
            
            n--;
        }
        return s;
    }
};