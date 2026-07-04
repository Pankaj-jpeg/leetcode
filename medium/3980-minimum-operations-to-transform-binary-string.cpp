////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3980. Minimum Operations to Transform Binary String
// Difficulty : Medium
// Link       : https://leetcode.com/problems/minimum-operations-to-transform-binary-string/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic string transformation | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 24 ms  |  Memory: 30.4 MB
// Date       : 2026-07-04
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int cnt = 0;
    
        if(n==1){
            if(s1[0] == '1' && s2[0] == '0')
                return -1;
            else if(s1[0] == s2[0])
                return 0;
            else
                return 1;
        }
        
        for(int i =0;i<n;i++){
            if(s1[i] == '0' && s2[i] == '1'){
                s1[i] = '1';
                cnt++;
            }

            if(s1[i] == '1' && s2[i] == '0'){
                if(i<n-1 && s1[i+1] == '1'){
                    if(s2[i+1] == '1')
                        cnt+=2;
                    else{
                        cnt+=1;
                        s1[i+1] = '0';
                    }
                }
                else if(i>0 && s1[i-1] == '1'){
                    cnt+=2;
                }
                else{
                    cnt+=2;
                }
                s1[i] = '0';
            }
        }

        return cnt;
        
    }
};