////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3. Longest Substring Without Repeating Characters
// Difficulty : Medium
// Link       : https://leetcode.com/problems/longest-substring-without-repeating-characters/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: sliding window, update left pointer on duplicate | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 11.5 MB
// Date       : 2026-07-05
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i =0;
        int j =0;
        vector<int> m(256,-1);
        int Max = 0;
        while(j<n){
            if(i == j){
                m[s[j]] = j;
            }
            else{
                if(m[s[j]] == -1){
                    m[s[j]] = j;
                }
                else{
                    if(m[s[j]] >= i){
                        i=m[s[j]]+1;
                        m[s[j]] = j;
                    }
                    else{
                        m[s[j]] = j;
                    }
                }
            }
            Max = max(Max,j-i+1);
            j++;
        }
        return Max;
    }
};