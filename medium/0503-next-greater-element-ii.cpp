////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 503. Next Greater Element II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/next-greater-element-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Monotonic stack | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 7 ms  |  Memory: 28.4 MB
// Date       : 2026-06-30
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> gt(n,-1);stack<int> stk;
        for(int i = 2*n-1;i>=0;i--){
            while(!stk.empty() && nums[i%n] >= stk.top())
                stk.pop();
            
            if(!stk.empty())
                gt[i%n] = stk.top();
            
            stk.push(nums[i%n]);
        }
        return gt;
    }
};