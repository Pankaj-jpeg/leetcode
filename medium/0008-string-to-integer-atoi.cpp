////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 8. String to Integer (atoi)
// Difficulty : Medium
// Link       : https://leetcode.com/problems/string-to-integer-atoi/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: parsing string from left to right, handling sign and leading zeros | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 7 ms  |  Memory: 9.1 MB
// Date       : 2026-07-16
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        

        int i = 0;
        while(s[i] == ' ')
            i++;
        
        if(s[i] =='-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }

        while(s[i] == '0')
            i++;
        

        //cout << i << " " << n;

        int res = 0;
        
        while((s[i] - '0') <= 9 && (s[i] - '0') >= 0){
            if((s[i]-'0') + (long long)res*10 <= INT_MAX){
                res = (s[i]-'0') + (long long)res*10;
                i++;
            }
            else{
                if(sign == -1)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
        }
        cout << res;
        return res*sign;

    }
};