////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2904. Shortest and Lexicographically Smallest Beautiful String
// Difficulty : Medium
// Link       : https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.6 MB
// Date       : 2026-08-26
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string curr = "";
        int n = s.size();
        int r = 0;
        int l = 0;
        int ones = 0;
        while(r < n){
            if(s[r] == '1'){
                ones++;
                if(ones == 1)
                    l = r;
            }
            if(ones == k){
                string temp = s.substr(l,r-l+1);
                if(curr == "" || curr.size() > r-l+1 || (curr.size() == r-l+1 && curr > temp))
                    curr =  temp; 
                while(l<r && s[l] != '1')
                    l++;
                l++;
                while(l<r && s[l]!='1')
                    l++;
                ones--;
            }
            //cout << l << " " << r << " " << curr << " " << ones<< "\n";
            r++;

           
        }
        return curr;
    }
};