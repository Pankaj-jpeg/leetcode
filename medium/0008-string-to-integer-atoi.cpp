////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 8. String to Integer (atoi)
// Difficulty : Medium
// Link       : https://leetcode.com/problems/string-to-integer-atoi/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: recursive depth-first search | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 2 ms  |  Memory: 10.2 MB
// Date       : 2026-06-17
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    // Helper function that carries the "running total" down the stack
    int convertRecursive(string s, int i, long currentTotal, int sign) {
        // Base Case 1: End of string reached
        if (i >= s.length()) {
            return currentTotal * sign;
        }
        
        // Base Case 2: Hit a non-digit character (Stop immediately!)
        if (s[i] < '0' || s[i] > '9') {
            return currentTotal * sign;
        }
        
        // Progress: Update the running total with the current digit
        currentTotal = currentTotal * 10 + (s[i] - '0');
        
        // Overflow Check: Catch it early on the way down
        if (sign == 1 && currentTotal > INT_MAX) return INT_MAX;
        if (sign == -1 && -currentTotal < INT_MIN) return INT_MIN;
        
        // Recursive Call: Move to the next index with the updated total
        return convertRecursive(s, i + 1, currentTotal, sign);
    }

    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        
        // 1. Skip whitespaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        
        // 2. Handle sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // 3. Kick off the recursion starting at index 'i', with an initial total of 0
        return convertRecursive(s, i, 0, sign);
    }
};