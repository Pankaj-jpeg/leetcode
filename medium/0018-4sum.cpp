////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 18. 4Sum
// Difficulty : Medium
// Link       : https://leetcode.com/problems/4sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 23 ms  |  Memory: 17.5 MB
// Date       : 2026-05-31
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool check_sorted(vector<int> nums){
            for(int i=1;i<nums.size();i++){
                if(nums[i] < nums[i-1])
                    return false;
            }
            return true;
        }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();long long sum;
        if(!check_sorted(nums))
            sort(nums.begin(),nums.end());
        vector<vector<int>> res;int k,l;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1;j<n;j++){
                if(j>i+1 && nums[j] == nums[j-1])
                    continue;
                l = j+1;
                k = n-1;
                while(l<k){
                    sum = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum==target){
                        res.push_back({nums[i],nums[j],nums[k],nums[l]});
                        l++;k--;
                        while(l<k && nums[l]==nums[l-1])
                            l++;
                        while(l<k && nums[k]==nums[k+1])
                            k--;
                    }
                    else{
                        if(sum > target)
                            k--;
                        else
                            l++;
                    }
                }
            }
        }
        return res;
    }
};