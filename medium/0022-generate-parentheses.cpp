////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 22. Generate Parentheses
// Difficulty : Medium
// Link       : https://leetcode.com/problems/generate-parentheses/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: backtracking with recursive depth-first search | Time: O(4^n / n^(3/2)) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 4 ms  |  Memory: 13.1 MB
// Date       : 2026-07-17
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void recur(vector<string>& res,string& curr,int& open_cnt,int& curr_cnt,int n){
        if(curr.size() == 2*n){
            res.push_back(curr);
            return;
        }

        //add ( 
        if(open_cnt < n){
            curr.push_back('(');open_cnt++;curr_cnt++;
            recur(res,curr,open_cnt,curr_cnt,n);
            open_cnt--;curr.pop_back();curr_cnt--;
        }

        //add )

        if(curr_cnt>0){
            curr.push_back(')');curr_cnt--;
            recur(res,curr,open_cnt,curr_cnt,n);
            curr_cnt++;curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        int open_cnt = 0;
        int curr_cnt = 0;
        recur(res,curr,open_cnt,curr_cnt,n);
        return res;
    }
};