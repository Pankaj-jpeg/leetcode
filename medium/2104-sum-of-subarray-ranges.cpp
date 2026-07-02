////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2104. Sum of Subarray Ranges
// Difficulty : Medium
// Link       : https://leetcode.com/problems/sum-of-subarray-ranges/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: stack-based range calculation | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 15.8 MB
// Date       : 2026-07-01
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> L1(n,0);
        vector<int> R1(n,0);
        vector<int> L2(n,0);
        vector<int> R2(n,0);
        stack<int> stk;
        for(int i =0;i<n;i++){
            while(!stk.empty() && nums[i] > nums[stk.top()])
                stk.pop();
            
            if(!stk.empty())
                L1[i] = i - stk.top() - 1;
            else
                L1[i] = i;
            
            stk.push(i);
        }

        while(!stk.empty())
            stk.pop();

        
        for(int i = n-1;i>=0;i--){
            while(!stk.empty() && nums[i] >= nums[stk.top()])
                stk.pop();
            if(!stk.empty())
                R1[i] = stk.top() - i - 1;
            else
                R1[i] = n - i -1;
            
            stk.push(i);
        }

        while(!stk.empty())
            stk.pop();

        for(int i =0;i<n;i++){
            while(!stk.empty() && nums[i] < nums[stk.top()])
                stk.pop();
            
            if(!stk.empty())
                L2[i] = i - stk.top() - 1;
            else
                L2[i] = i;
            
            stk.push(i);
        }

        while(!stk.empty())
            stk.pop();

        
        for(int i = n-1;i>=0;i--){
            while(!stk.empty() && nums[i] <= nums[stk.top()])
                stk.pop();
            if(!stk.empty())
                R2[i] = stk.top() - i - 1;
            else
                R2[i] = n - i -1;
            
            stk.push(i);
        }
        long long max_tot = 0;
        long long min_tot = 0;

        for(int i = 0;i<n;i++){
            max_tot += (long)nums[i]*(L1[i] + 1)*(R1[i] + 1);
            min_tot += (long)nums[i]*(L2[i] + 1)*(R2[i] + 1);
        }
    
        return max_tot - min_tot;
    }
};