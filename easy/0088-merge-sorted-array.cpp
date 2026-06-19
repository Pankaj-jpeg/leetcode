////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 88. Merge Sorted Array
// Difficulty : Easy
// Link       : https://leetcode.com/problems/merge-sorted-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique from end | Time: O(m+n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 12.4 MB
// Date       : 2026-06-01
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i=m-1;
       int j=n-1;
       int k=m+n-1;

       while(j>=0){
            if(i>=0 && nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;i--;
            }
            else{
                nums1[k] = nums2[j];
                k--;j--;
            }
       }
       
    }
};