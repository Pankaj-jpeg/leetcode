////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 56. Merge Intervals
// Difficulty : Medium
// Link       : https://leetcode.com/problems/merge-intervals/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: greedy, merge adjacent intervals | Time: O(n log n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 23.9 MB
// Date       : 2026-08-08
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int i = 1;
        int curr_st = -1;
        int curr_end = -1;


        sort(intervals.begin(),intervals.end());

        for(int i = 0;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(curr_st == -1 && curr_end == -1){
                curr_st = start;
                curr_end = end;
                continue;
            }
            else if(curr_end < start){
                res.push_back({curr_st,curr_end});
                curr_st = start;
                curr_end = end;
            }
            else{
                curr_st = min(start,curr_st);
                curr_end = max(end,curr_end);
            }
        }

        if(curr_st != -1 && curr_end != -1){
            res.push_back({curr_st,curr_end});
        }

        return res;
    }
};