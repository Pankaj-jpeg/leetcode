////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 5. Longest Palindromic Substring
// Difficulty : Medium
// Link       : https://leetcode.com/problems/longest-palindromic-substring/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Manacher's algorithm | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 2 ms  |  Memory: 11.2 MB
// Date       : 2026-06-15
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;

        // 1. Manually transform string without regex (O(n))
        string T = "^";
        for (char c : s) {
            T += "#";
            T += c;
        }
        T += "#$"; // Use bounds ^ and $ to avoid out-of-bounds checking loops

        int n = T.length();
        vector<int> P(n, 0);
        int center = 0, right = 0;
        int maxLen = 0, maxCenter = 0;

        // 2. Core Manacher's logic
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * center - i;
            
            if (right > i) {
                P[i] = min(right - i, P[i_mirror]);
            }

            // Expand around center i (safe due to ^ and $ boundaries)
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                P[i]++;
            }

            // Adjust center if palindrome expands past right bound
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }

            // Track the absolute max palindrome found
            if (P[i] > maxLen) {
                maxLen = P[i];
                maxCenter = i;
            }
        }

        // 3. Extract the answer cleanly using math, ONE time.
        int start = (maxCenter - 1 - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};