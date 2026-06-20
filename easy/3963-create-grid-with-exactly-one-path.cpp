////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3963. Create Grid With Exactly One Path
// Difficulty : Easy
// Link       : https://leetcode.com/problems/create-grid-with-exactly-one-path/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: simple string manipulation | Time: O(m*n) | Space: O(m*n)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 11.7 MB
// Date       : 2026-06-20
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        string curr(n,'.');
        res.push_back(curr);
        curr.clear();
        for(int i =0;i<n;i++){
            if(i==n-1)
                curr.push_back('.');
            else
                curr.push_back('#');
        }
        for(int i=1;i<m;i++){
            res.push_back(curr);
        }
        return res;
    }
};