////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 28. Find the Index of the First Occurrence in a String
// Difficulty : Easy
// Link       : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: KMP-like string matching with a simple sliding window | Time: O(n*m) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 99 ms  |  Memory: 9.2 MB
// Date       : 2026-01-11
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;int j=0;int k;bool flag;
        while(haystack[i]!='\0'){
            k=i;
            flag=true;
            while(needle[j]!='\0' && flag){
                if(needle[j] == haystack[k]){
                    k++;
                    j++;
                }
                else{
                    flag=false;
                }

            }
            if(!(flag))
                j=0;
            if(flag){
                return i;
            }
            i++;
        }
        return -1;
    }
};