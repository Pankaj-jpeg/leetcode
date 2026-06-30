////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 496. Next Greater Element I
// Difficulty : Easy
// Link       : https://leetcode.com/problems/next-greater-element-i/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: stack-based next greater element search | Time: O(n + m) | Space: O(n + m)
// Time       : 
// Space      : 
// Runtime    : 1 ms  |  Memory: 12.9 MB
// Date       : 2026-06-30
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;unordered_map <int,int> m;
        for(int i = nums2.size()-1;i>=0;i--){
            while(!stk.empty() && nums2[i] > stk.top()){
                stk.pop();
            }
            if(stk.empty())
                m.insert({nums2[i],-1});
            else
                m.insert({nums2[i],stk.top()});
            
            stk.push(nums2[i]);
        }

        for(int i =0;i<nums1.size();i++){
           nums1[i] = m.find(nums1[i])->second;
        }

        return nums1;
    }
};