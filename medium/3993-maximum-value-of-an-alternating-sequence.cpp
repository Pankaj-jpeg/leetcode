////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3993. Maximum Value of an Alternating Sequence
// Difficulty : Medium
// Link       : https://leetcode.com/problems/maximum-value-of-an-alternating-sequence/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: mathematical formula application | Time: O(1) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 9.2 MB
// Date       : 2026-07-18
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1)
            return s;

        long long temp;
        if(n%2 == 0){
            temp = s + (long long)(n/2)*m - (long long)((n/2)-1);
            return temp;
        }
        else{
            temp = s + (long long)(n/2)*m - (long long)(n/2);
            return temp+1;
        }
        
        
    }
};