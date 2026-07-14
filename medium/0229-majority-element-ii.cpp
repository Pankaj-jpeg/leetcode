////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 229. Majority Element II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/majority-element-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Boyer-Moore Majority Vote algorithm with two counters | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 23.7 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1;
        int ele2;
        int cnt1 = 0;
        int cnt2 = 0;
        vector<int> res;

        for(int i = 0;i<n;i++){
            if(cnt1 == 0 && nums[i]!=ele2){
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i]!=ele1){
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(ele1 == nums[i])cnt1++;
            else if(ele2 == nums[i])cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        int cnt_ele1 = 0;
        int cnt_ele2 = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == ele1)
                cnt_ele1++;
            else if(nums[i] == ele2)
                cnt_ele2++;
        }

        if(cnt_ele1 > n/3)
            res.push_back(ele1);
        if(cnt_ele2 > n/3)
            res.push_back(ele2);

        return res;
    }
};