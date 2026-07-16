////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 151. Reverse Words in a String
// Difficulty : Medium
// Link       : https://leetcode.com/problems/reverse-words-in-a-string/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two passes, first to remove extra spaces and then to reverse words | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 9.9 MB
// Date       : 2026-07-16
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0;


        //remove leading whitespace
        while(s[i] == ' '){
            i++;
        }
        s.erase(0,i);

        //removing trailing whitespace
        int n = s.size();   
        i = n-1;
        while(s[i] == ' ')
            i--;
        
        s.erase(i+1,n-1-i);

        //remove extra spaces
        i = 0;
        j = 0;
        n = s.size();

        while(i<n){
            if(s[i]!=' '){
                s[j] = s[i];
                i++;
                j++;
            }
            else{
                s[j] = s[i];
                j++;
                while(i<n && s[i] == ' ')
                    i++;

            }

        }
        s.resize(j);

        i = 0;
        j = 0;
        n = s.size();
        while(i<n){
            if(s[i] != ' ')
                i++;
            else{
                reverse(s.begin()+j,s.begin()+i);
                i++;
                j = i;
            }
        }
        if(i>j)
            reverse(s.begin()+j,s.begin()+i);
        
        reverse(s.begin(),s.end());


        return s;
    }
};