////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 907. Sum of Subarray Minimums
// Difficulty : Medium
// Link       : https://leetcode.com/problems/sum-of-subarray-minimums/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two passes, stack-based | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 82 ms  |  Memory: 193.5 MB
// Date       : 2026-07-21
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long temp = 1000000007;
        int n = arr.size();
        vector<int> L(n,-1);
        vector<int> R(n,n);
        long long total = 0;
        stack<int> stk;

        for(int i = n-1;i>=0;i--){
            while(!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            
            if(!stk.empty())
                R[i] = stk.top();
            
            stk.push(i);
        }


        while(!stk.empty())
            stk.pop();


        for(int i = 0;i<n;i++){
            while(!stk.empty() && arr[stk.top()] > arr[i])
                stk.pop();
            
            if(!stk.empty())
                L[i] = stk.top();
            
            stk.push(i);
        }


        for(int i = 0;i<n;i++){
            total += ((long long)arr[i]*(long long)(i-L[i])*(long long)(R[i]-i)) % temp;
        }

        return total%temp;
    }
};