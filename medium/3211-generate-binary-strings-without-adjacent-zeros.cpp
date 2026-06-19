////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3211. Generate Binary Strings Without Adjacent Zeros
// Difficulty : Medium
// Link       : https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: depth-first search with backtracking | Time: O(2^n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 4 ms  |  Memory: 22.7 MB
// Date       : 2026-06-18
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<string> res;string curr ="";int N;
    void generator(char c,int n){
        curr += c;
        if(curr.length() == n){
            res.push_back(curr);curr.pop_back();
            return;
        }

        if(c!='0'){
            generator('0',n);
        }
        generator('1',n);
        curr.pop_back();

    }
    vector<string> validStrings(int n) {
        generator('0',n);
        generator('1',n);
    
        return res;
    }
};