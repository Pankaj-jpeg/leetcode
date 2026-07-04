////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 239. Sliding Window Maximum
// Difficulty : Hard
// Link       : https://leetcode.com/problems/sliding-window-maximum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: deque-based sliding window, maintain max element in window | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 17 ms  |  Memory: 139.2 MB
// Date       : 2026-07-03
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> Max;
        deque<int> q;

        for(int i =0 ;i<n;i++){
            if(q.front() == (i-k))
                q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();

            q.push_back(i);
            if(i >= k-1){
                Max.push_back(nums[q.front()]);
            }
        }

    return Max;

    }   
};