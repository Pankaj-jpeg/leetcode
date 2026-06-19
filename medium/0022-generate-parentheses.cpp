////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 22. Generate Parentheses
// Difficulty : Medium
// Link       : https://leetcode.com/problems/generate-parentheses/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: backtracking with recursive depth-first search | Time: O(4^n / n^(3/2)) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 13.3 MB
// Date       : 2026-06-18
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<string> res;string curr = "";
    void generator(char ch,int n,int count_for,int count_back){
        curr+=ch;
        if(curr.length() == 2*n){
            res.push_back(curr);curr.pop_back();
            return;
        }
        if(count_back)
            generator(')',n,count_for,count_back-1);
        if(count_for)
            generator('(',n,count_for-1,count_back+1);

        curr.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        generator('(',n,n-1,1);

        return res;
    }
};