////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1358. Number of Substrings Containing All Three Characters
// Difficulty : Medium
// Link       : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: sliding window, update minimum position | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 6 ms  |  Memory: 11.1 MB
// Date       : 2026-07-06
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        int l = 0;
        vector<int> last_pos(3,-1);

        for(int r = 0;r<n;r++){
            last_pos[s[r]-'a'] = r;
            int Min_pos = min(last_pos[0],min(last_pos[1],last_pos[2]));
            if(Min_pos!= -1){
                cnt+=(Min_pos+1);
            }
                
        }
        return cnt;
    }
};