////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 14. Longest Common Prefix
// Difficulty : Easy
// Link       : https://leetcode.com/problems/longest-common-prefix/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique, iterate through characters | Time: O(n*m) | Space: O(n*m))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 11.8 MB
// Date       : 2026-06-13
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string res = "";
        int j=0;int min_length = INT_MAX;
        for(int i = 0;i<s.size();i++){
            min_length = std::min(min_length,(int)s[i].size());
        }
        bool flag;
        while(j<min_length){
            flag = true;
            char curr = s[0][j];
            for(int i=0;i<s.size();i++){
                if(curr != s[i][j]){
                    flag = false;
                    break;
                }
            }
            if(flag == false){
                break;
            }
            else{
                res.push_back(s[0][j]);
                j++;
            }
        }
        return res;
    }
};