////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 57. Insert Interval
// Difficulty : Medium
// Link       : https://leetcode.com/problems/insert-interval/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique with merging overlapping intervals | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 21.7 MB
// Date       : 2026-07-09
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();

        if(n == 0){
            res.push_back(newInterval);
            return res;
        }
        int i = 0;
        while(i<n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0] , newInterval[0]);
            newInterval[1] = max(intervals[i][1] , newInterval[1]);
            i++;
        }
        res.push_back(newInterval);

        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
       return res;
    }
};