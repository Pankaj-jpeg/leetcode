////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 4006. Count Valid Prefixes
// Difficulty : Easy
// Link       : https://leetcode.com/problems/count-valid-prefixes/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two counters for zeros and ones, increment valid prefix count on equality or consecutive difference | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 9.5 MB
// Date       : 2026-08-01
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int countValidPrefixes(string s) {
        char start = s[0];

        int cnt = 0;
        int cnt_one = 0;
        int cnt_zero = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '0')
                cnt_zero++;
            else
                cnt_one++;


            if(cnt_zero == cnt_one)
                cnt++;
            if(cnt_zero == (cnt_one + 1) || cnt_one == (cnt_zero + 1))
                cnt++;
        }


        return cnt;
    }
};