////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 15. 3Sum
// Difficulty : Medium
// Link       : https://leetcode.com/problems/3sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique with duplicate handling | Time: O(n^2) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 39 ms  |  Memory: 29.4 MB
// Date       : 2026-05-30
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(!check_sorted(nums))
            sort(nums.begin(),nums.end());
        vector<vector<int>> res;int j=1,k=n-1;int temp;
        for(int i =0;i<n;i++){
             if(i>0 && nums[i] == nums[i-1])
            {   
                continue;
            }
             j=i+1;
            k=n-1;
           
            
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    temp = nums[j];
                    j++;
                    while(j<k && nums[j]==temp)
                        j++;
                }
                else{
                    if(sum < 0){
                        j++;
                    }
                    else{
                        k--;
                    }
                }
            }
           
        }
        return res;
    }
};