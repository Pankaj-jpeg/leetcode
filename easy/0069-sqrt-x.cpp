////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 69. Sqrt(x)
// Difficulty : Easy
// Link       : https://leetcode.com/problems/sqrtx/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.5 MB
// Date       : 2026-06-26
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int mySqrt(int x) {
        long low = 1;
        long high = x/2 + 1 ;
        long mid;
        
        if(x==0) 
            return 0;
        if(x==1 || x==2 || x==3)
            return 1;
        while(low<high){
            mid = low + (high-low)/2;
            if(mid*mid < x)
                low = mid+1;
            else
                high = mid;
        }
        if(low*low == x)
            return low;
        else{
            if(low*low < x)
                return low+1;
            else
                return low-1;
        }
    }
};