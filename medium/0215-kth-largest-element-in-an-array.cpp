////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 215. Kth Largest Element in an Array
// Difficulty : Medium
// Link       : https://leetcode.com/problems/kth-largest-element-in-an-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: maintaining a max heap of size k | Time: O(n log k) | Space: O(k)
// Time       : 
// Space      : 
// Runtime    : 26 ms  |  Memory: 72.7 MB
// Date       : 2026-07-24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(nums[0]);
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] < pq.top() && pq.size() == k)
                continue;
            else{
                pq.push(nums[i]);
                if(pq.size() > k)
                    pq.pop();
            }
        }

        return pq.top();
    }
};