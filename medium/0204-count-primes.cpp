////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 204. Count Primes
// Difficulty : Medium
// Link       : https://leetcode.com/problems/count-primes/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Sieve of Eratosthenes | Time: O(n log log n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 191 ms  |  Memory: 12.7 MB
// Date       : 2026-06-24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;vector<bool> primes(n,true);
        for(int i = 2;i<n;i++){
            if(primes[i]){
                cnt++;
                for(long j = (long)i*i;j<n;j+=i){
                    primes[j] = false;
                }
            }
        }
        return cnt;
    }
};