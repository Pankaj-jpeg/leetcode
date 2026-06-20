////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 17. Letter Combinations of a Phone Number
// Difficulty : Medium
// Link       : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: backtracking | Time: O(4^n) | Space: O(4^n))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 9.4 MB
// Date       : 2026-06-19
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<string> res;string curr="";
    vector<string> strs = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void generator(string digits,int idx){
        if(idx == digits.length() && curr.length() == digits.length()){
            res.push_back(curr);
            return;
        }
        int num = digits[idx] - '0';
        for(auto itr : strs[num]){
            curr.push_back(itr);
            generator(digits,idx+1);
            curr.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        generator(digits,0);
        return res;
    }
};