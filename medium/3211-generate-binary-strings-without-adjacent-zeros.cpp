////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3211. Generate Binary Strings Without Adjacent Zeros
// Difficulty : Medium
// Link       : https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: backtracking with pruning | Time: O(2^n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 20.9 MB
// Date       : 2026-07-17
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void recur(vector<string>& res,string& curr,int n){
        if(curr.size() == n){
            res.push_back(curr);
            return;
        }
        
        //add 1
        curr.push_back('1');
        recur(res,curr,n);
        curr.pop_back();

        //add 0
        if(curr.size()==0 || curr.back() == '1'){
            curr.push_back('0');
            recur(res,curr,n);
            curr.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string> res;
        string curr = "";
        recur(res,curr,n); 

        return res;   
    }
};