////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 402. Remove K Digits
// Difficulty : Medium
// Link       : https://leetcode.com/problems/remove-k-digits/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: stack, pop smaller digits until k is reached | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 12.5 MB
// Date       : 2026-07-01
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k)
            return "0";
        
        stack<int,vector<int>> stk;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            while(!stk.empty() && num[i] < stk.top() && cnt!=k){
                stk.pop();cnt++;
            }

            stk.push(num[i]);
        }

        if(cnt<k){
            while(!stk.empty() && cnt!=k){
                stk.pop();
                cnt++;
            }
        }

        string res="";
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        while(res.size()!=0 && res.back() == '0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res.size() == 0)
            return "0";
        return res;
    }
};