////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 455. Assign Cookies
// Difficulty : Easy
// Link       : https://leetcode.com/problems/assign-cookies/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique | Time: O(m log m + n log n) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 4 ms  |  Memory: 45 MB
// Date       : 2026-07-08
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int m = g.size();
        int n = s.size();
        int satisfied = 0;
        int i = 0;
        int j = 0;
        while(i<m && j<n){
            if(g[i] <= s[j]){
                satisfied++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }


        return satisfied;
    }
};