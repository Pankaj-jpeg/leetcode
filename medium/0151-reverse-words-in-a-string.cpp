////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 151. Reverse Words in a String
// Difficulty : Medium
// Link       : https://leetcode.com/problems/reverse-words-in-a-string/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two passes, first reverse the entire string and then reverse each word | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 10 MB
// Date       : 2026-06-13
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string reverseWords(string s) {
        int i = 0,j = s.length();
        while(i<j){
            int start = i;
            while(i < j && s[i]!=' '){
                i++;
            }
            int next = i;
            i--;
            
            while(start<i){
                swap(s[start],s[i]);
                start++;i--;
            }
            i = next;
            i++;
        }
        j = s.length()-1;
        i = 0;
        while(i < j){
            swap(s[i],s[j]);
            i++;j--;
        }
        cout << s;
        i = 0;int n = s.length();
        int wrt = 0;
        while(i<n){
            while(s[i] == ' '){
                i++;
            }
            while(i < n && s[i] != ' '){
                if(s[i] == ' '){
                    i++;continue;
                }
                s[wrt++] = s[i++];
            }
            while(s[i] == ' '){
                i++;
            }
            if(i < n)
                s[wrt++] = ' ';
        }
        
        return s.substr(0,wrt);
    }
};