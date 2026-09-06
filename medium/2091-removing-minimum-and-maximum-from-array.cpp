////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2091. Removing Minimum and Maximum From Array
// Difficulty : Medium
// Link       : https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 92.1 MB
// Date       : 2026-09-01
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int Min_idx = -1;
        int Max_idx = -1;


        int Min = INT_MAX;
        int Max = INT_MIN;

        for(int i = 0;i<nums.size();i++){
            if(Min > nums[i]){
                Min_idx = i;
                Min = nums[i];
            }
            if(Max < nums[i]){
                Max_idx = i;
                Max = nums[i];
            }
        }
        //cout << Min_idx << " " << Max_idx;
        int start = min(Min_idx,Max_idx);
        int end = max(Min_idx,Max_idx);
        int n = nums.size();
        int cnt = min((start + 1) + (n-end),min(end+1,n-start));

        return cnt;
    }
};