////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3982. Sum of Integers with Maximum Digit Range
// Difficulty : Easy
// Link       : https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic digit range calculation | Time: O(n*m) | Space: O(10)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 31 MB
// Date       : 2026-07-05
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int Max_range = INT_MIN;
        vector<int> range(10,0);
        for(int i =0;i<n;i++){
            int Max = 0;int Min = 9;
            int num = nums[i];
            while(num>0){
                int r =num%10;
                Max = max(Max,r);
                Min = min(Min,r);
                num = num/10;
            }
            range[Max-Min]+=nums[i];
            Max_range = max(Max_range,Max-Min);
        }
        return range[Max_range];
    }
};