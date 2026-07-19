////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 50. Pow(x, n)
// Difficulty : Medium
// Link       : https://leetcode.com/problems/powx-n/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: divide and conquer, using exponentiation by squaring | Time: O(log(n)) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.6 MB
// Date       : 2026-07-19
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            x = 1/x;
        }
        long long nums = labs(n);
        double Pow = 1;
        while(nums!=0){
            if((nums&1))Pow *= x;

            x*=x;
            nums=(nums>>1);
        }

        return Pow;
    }
};