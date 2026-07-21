////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 496. Next Greater Element I
// Difficulty : Easy
// Link       : https://leetcode.com/problems/next-greater-element-i/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: stack, pop smaller elements from right to left | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 12.7 MB
// Date       : 2026-07-21
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int,int> m;
        for(int i = nums2.size()-1;i>=0;i--){
            while(!stk.empty() && stk.top() < nums2[i])
                stk.pop();
            

            int larger = stk.empty() ? -1 : stk.top();
            m.insert({nums2[i],larger});
            stk.push(nums2[i]);
        }
        for(int i = 0;i<nums1.size();i++)
            nums1[i] = m[nums1[i]];
        
        return nums1;
    }
};