////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 215. Kth Largest Element in an Array
// Difficulty : Medium
// Link       : https://leetcode.com/problems/kth-largest-element-in-an-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: using a max heap (priority queue) to maintain the k largest elements | Time: O(n log k) | Space: O(k)
// Time       : 
// Space      : 
// Runtime    : 39 ms  |  Memory: 61.5 MB
// Date       : 2026-01-11
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};