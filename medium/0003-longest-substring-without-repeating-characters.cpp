////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3. Longest Substring Without Repeating Characters
// Difficulty : Medium
// Link       : https://leetcode.com/problems/longest-substring-without-repeating-characters/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: sliding window with two pointers, expand right on new char and shrink left on duplicate | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 11.6 MB
// Date       : 2026-07-22
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int Max = 0;
        vector<int> freq(256,0);
        int i = 0;
        int j = 0;


        while(i<n){
            if(freq[s[i]] == 0){
                freq[s[i]]++;
                Max = max(Max,i-j+1);
            }
            else{
                while(s[j] != s[i]){
                    freq[s[j]]--;
                    j++;
                }
                j++;
            }
            Max = max(Max,i-j+1);
            i++;
        }

        return Max;
        
    }
};