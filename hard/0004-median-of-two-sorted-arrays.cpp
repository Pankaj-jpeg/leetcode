////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 4. Median of Two Sorted Arrays
// Difficulty : Hard
// Link       : https://leetcode.com/problems/median-of-two-sorted-arrays/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search for partition point | Time: O(log(min(m,n))) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 95.2 MB
// Date       : 2026-07-15
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if(m > n){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int low = 0;
        int high = m;

        int m1;
        int m2;

        while(low<=high){
            m1 = low + (high-low)/2;
            m2 = (m+n+1)/2 - m1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;

            if(m1 > 0)
                l1 = nums1[m1-1];
            if(m2 > 0)
                l2 = nums2[m2-1];
            if(m1 < m)
                r1 = nums1[m1];
            if(m2 < n)
                r2 = nums2[m2];
        

            if(l1 <= r2 && l2 <= r1){
                if((m+n)%2 == 0){
                    return (double)(max(l1,l2) + min(r1,r2))/2.0;
                }
                else
                    return max(l1,l2);
            }

            else if(l1 > r2)
                high = m1-1;
            else
                low = m1+1;
        }


        return -1;
    }
};