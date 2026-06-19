////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 560. Subarray Sum Equals K
// Difficulty : Medium
// Link       : https://leetcode.com/problems/subarray-sum-equals-k/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: prefix sum with hash map | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 32 ms  |  Memory: 45.4 MB
// Date       : 2026-05-26
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> map;int sum=0;int cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
                cnt++;
            }
            if(map.find(sum-k)!=map.end()){
                cnt+=map[sum-k];
            }
            if(map.find(sum) == map.end()){
                map.insert({sum,1});
            }
            else{
                map[sum]++;
            }
        }
        return cnt;
    }
};