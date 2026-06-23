////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 29. Divide Two Integers
// Difficulty : Medium
// Link       : https://leetcode.com/problems/divide-two-integers/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search-like division using bit shifting | Time: O(log(dividend)) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.5 MB
// Date       : 2026-06-23
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        int sign = 1;
        if(dividend < 0){
            sign = (-1)*sign;
        }
        if(divisor<0){
            sign = (-1)*sign;
        }
        unsigned int a = (dividend < 0) ? -(long)dividend : dividend;
        unsigned int b =  (divisor < 0) ? -(long)divisor : divisor;
        long temp = b;long sum = 0;long q = 1;
        while(a >= b){
            temp = temp << 1;
            q = q << 1;
            if(temp > a){
                temp = temp >> 1;q = q >> 1;
                sum+=(q);
                a = a - temp;
                temp = b;q =1;
            }
        }
        if(sum > INT_MAX){
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        return sign == 1 ? sum : -sum;
    }   
};