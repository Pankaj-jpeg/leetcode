////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 69. Sqrt(x)
// Difficulty : Easy
// Link       : https://leetcode.com/problems/sqrtx/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(log(n)) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.6 MB
// Date       : 2026-07-15
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x/2;
        int mid ;

        if(x == 0)
            return 0;

        while(low<high){
            mid = low + (high-low)/2;

            if((long long)mid*mid >= x)
                high = mid;
            else
                low = mid+1;
        }

        if((long long)low*low == x)
            return low;

        if((long long)low*low > x)
            return low-1;
        else
            return low;
    }
};