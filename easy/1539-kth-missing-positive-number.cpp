////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1539. Kth Missing Positive Number
// Difficulty : Easy
// Link       : https://leetcode.com/problems/kth-missing-positive-number/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search | Time: O(log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 13.3 MB
// Date       : 2026-06-11
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low=0;
        int high = arr.size()-1;int mid;
        while(low<high){
            mid = low + (high-low)/2;
            if(arr[mid] - (mid+1) >= k){
                high = mid;
            }
            else
                low = mid+1;
        }
        if(arr[low] - (low+1) >= k){
            int dec = arr[low] - (low+1) - k + 1;
            return arr[low] - dec;
        }
        else{
            int inc = k - (arr[low] - (low+1));
            return arr[low] + inc;
        }
    }
};