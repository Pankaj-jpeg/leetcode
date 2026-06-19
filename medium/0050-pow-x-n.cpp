////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 50. Pow(x, n)
// Difficulty : Medium
// Link       : https://leetcode.com/problems/powx-n/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: recursive exponentiation | Time: O(log n) | Space: O(log n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.8 MB
// Date       : 2026-06-17
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    double myPow(double x, int n) {
        if(x==1 || n==0)
            return 1;
        if(n < 0){
            if(n == INT_MIN)
                return 1/x*myPow(x,n+1);
            return 1/myPow(x,(-1)*n);
        }
        if(n==1)
            return x;
        
        if(n%2 == 0)
            return (myPow(x*x,n/2));
        else
            return (x*myPow(x*x,(n-1)/2));
    }

};