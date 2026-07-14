////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1752. Check if Array Is Sorted and Rotated
// Difficulty : Easy
// Link       : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: find the first drop and check if the array is sorted after it | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 11.3 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drops = 0;
        int j=-1;
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i] < nums[i-1]){
                drops++;
                j = i;
            }
        }
        if(j == -1)
            return true;

        int k = j+1;
        while( k % n != j){
            if(nums[k%n] < nums[(k-1)%n])
                return false;
            
            k++;
        }

        return true;
    }
};