////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3959. Check Good Integer
// Difficulty : Easy
// Link       : https://leetcode.com/problems/check-good-integer/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: calculate the sum of digits and the sum of squares of digits | Time: O(log(n)) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 7.7 MB
// Date       : 2026-06-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum =0 ;int ssum=0;int r;
        if(n==0){
            return false;
        }
        while(n>0){
            r = n%10;
            n = n/10;
            sum+=r;
            ssum+=r*r;
        }

        return ssum - sum >= 50;
        
    }
};