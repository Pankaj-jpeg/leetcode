////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1781. Sum of Beauty of All Substrings
// Difficulty : Medium
// Link       : https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: brute force with nested loops, calculating frequency of each character in substring | Time: O(n^3) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 13 ms  |  Memory: 9.9 MB
// Date       : 2026-06-15
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();int min_cnt = 1;
        vector<int> freq(26);int max=INT_MIN;int min=INT_MAX;int res = 0;
        for(int i = 0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                freq[s[j]-'a']++;

                if(max < freq[s[j]-'a'])
                    max = freq[s[j]-'a'];

                
                if(min > freq[s[j]-'a']){
                    min = freq[s[j]-'a'];
                    min_cnt = 1;;
                }
                else if(min == freq[s[j] -'a']){
                    min_cnt++;
                }
                else if(min+1 == (freq[s[j]-'a']) && --min_cnt == 0){
                    min++;
                    for(int k=0;k<26;k++){
                        if(min == freq[k])
                            min_cnt++;
                    }
                }


                if(max-min!=0)
                    res+=max-min;

                
            }
            max = INT_MIN;
            min = INT_MAX;min_cnt=1;
            freq.assign(26,0);
        }
        
        return res;
    }

};