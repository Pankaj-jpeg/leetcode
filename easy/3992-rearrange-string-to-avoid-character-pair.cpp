////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3992. Rearrange String to Avoid Character Pair
// Difficulty : Easy
// Link       : https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: greedy, prioritize characters with higher frequency | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 9.5 MB
// Date       : 2026-07-18
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        vector<int> freq(26,0);

        for(int i = 0;i<s.size();i++){
            freq[s[i]-'a']++;
        }

        string t = "";
        while(freq[y-'a'] > 0){
            t.push_back(y);
            freq[y-'a']--;
        }

        for(int i = 0;i<26;i++){
            if(i == x-'a' || freq[i] == 0) continue;
            while(freq[i]>0){
                t.push_back(i+'a');
                freq[i]--;
            }
        }

        while(freq[x-'a'] > 0){
            t.push_back(x);
            freq[x-'a']--;
        }

        return t;
    }
};