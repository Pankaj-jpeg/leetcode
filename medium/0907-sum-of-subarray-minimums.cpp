////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 907. Sum of Subarray Minimums
// Difficulty : Medium
// Link       : https://leetcode.com/problems/sum-of-subarray-minimums/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique with stack | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 31 ms  |  Memory: 191.9 MB
// Date       : 2026-07-01
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long temp = pow(10,9) + 7;
        int n = arr.size();
        long total = 0;
        vector<int> L(n,0);
        vector<int> R(n,0);
        stack<int,vector<int>> stk;
        for(int i = 0;i<n;i++){
            while(!stk.empty() && arr[i] < arr[stk.top()])
                stk.pop();
            
            if(!stk.empty())
                L[i] = i - (stk.top()) - 1;
            else
                L[i] = i;
            stk.push(i);
        }
        while(!stk.empty()) 
            stk.pop();
        for(int i = n-1;i>=0;i--){
            while(!stk.empty() && arr[i] <= arr[stk.top()])
                stk.pop();
            
            if(!stk.empty())
                R[i] = stk.top() - i - 1;
            else
                R[i] = (n-1) - i;
            stk.push(i);
        }
        
        for(int i = 0;i<n;i++){
            total = (total + (long)arr[i]*(L[i]+1)*(R[i]+1))%temp;
        }

        return total;
    }
};