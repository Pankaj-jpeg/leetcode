////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 424. Longest Repeating Character Replacement
// Difficulty : Medium
// Link       : https://leetcode.com/problems/longest-repeating-character-replacement/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: sliding window, maintain max frequency | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 1 ms  |  Memory: 10.9 MB
// Date       : 2026-07-06
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        char letter = '#';
        vector<int> freq(26,0);
        int Max_f = 0;
        int l = 0;
        int Max = 0;
        for(int r = 0;r<n;r++){
            freq[s[r]-'A']++;
            Max_f = max(Max_f,freq[s[r]-'A']);
            if(r-l+1 - Max_f > k){
                freq[s[l]-'A']--;
                l++;
            }
            Max = max(Max, r-l+1);
        }


        return Max;
    }
};