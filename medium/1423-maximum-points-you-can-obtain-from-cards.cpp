////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1423. Maximum Points You Can Obtain from Cards
// Difficulty : Medium
// Link       : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: prefix sum and two-pointer technique | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 46.1 MB
// Date       : 2026-07-06
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        int lsum = 0;
        int rsum = 0;
        int Max = 0;
        

        int l = k-1;
        int r = n-1;
        
        for(int i = 0;i<k;i++){
            lsum+=cardPoints[i];
        }
        sum = lsum+rsum;
        Max = max(Max,sum);
        while(l>=0){
            lsum-=cardPoints[l];
            l--;
            rsum+=cardPoints[r];
            r--;
            sum = lsum+rsum;
            Max = max(Max,sum);
        }
        return Max;
    }
};