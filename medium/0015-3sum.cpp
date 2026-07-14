////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 15. 3Sum
// Difficulty : Medium
// Link       : https://leetcode.com/problems/3sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique with sorting | Time: O(n^2) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 51 ms  |  Memory: 29.1 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        int i = 0;
        while(i<n){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    int key1 = nums[j];
                    int key2 = nums[k];
                    while(j<n && nums[j] == key1)j++;
                    while(k>i && nums[k] == key2)k--;
                }
                else if(sum < 0){
                    j++;
                }
                else
                    k--;
            }
            int key = nums[i];
            while(i<n && nums[i]==key)i++;
        }

        return res;
    }
};