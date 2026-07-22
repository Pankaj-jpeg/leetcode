////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 239. Sliding Window Maximum
// Difficulty : Hard
// Link       : https://leetcode.com/problems/sliding-window-maximum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: sliding window, maintain max element in deque | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 23 ms  |  Memory: 139.3 MB
// Date       : 2026-07-22
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        deque<int> q;
        for(int i = 0;i<n;i++){ 
            if(q.front() == (i-k))
                q.pop_front();
            
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            
            q.push_back(i);
        
            if(i >= k-1){
                res.push_back(nums[q.front()]);
            }   
        }

        return res;

    }   
};