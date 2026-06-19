////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1922. Count Good Numbers
// Difficulty : Medium
// Link       : https://leetcode.com/problems/count-good-numbers/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with memoization | Time: O(log(n)) | Space: O(log(n)))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 7.8 MB
// Date       : 2026-06-18
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    const long temp = (int)pow(10,9) + 7;
    long long count_even(long long n){
        if(n == 0)
            return 1;
        if(n==1)
        {
            return 5;
        }
        long long k;
        k = count_even(n/2);
        if(n%2==0)
            return (k*k)%temp;
        else
            return (5*k*k)%temp;
    }
    long long count_prime(long long n){
        if(n == 0)
            return 1;
        if(n==1)
            return 4;
        
        long long dummy;
        dummy = count_prime(n/2);
        if(n%2==0)
            return (dummy*dummy)%temp;
        else
            return (4*dummy*dummy)%temp;
    }
    int countGoodNumbers(long long n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 5;
        if(n%2==0)
            return (count_even(n/2)*count_prime(n/2))%temp;
        else
            return (count_even(n/2 + 1)*count_prime(n/2))%temp;
    }
};