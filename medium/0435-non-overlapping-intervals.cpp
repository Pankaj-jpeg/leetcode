////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 435. Non-overlapping Intervals
// Difficulty : Medium
// Link       : https://leetcode.com/problems/non-overlapping-intervals/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: sorting intervals by end time and then iterating to find overlapping intervals | Time: O(n log n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 57 ms  |  Memory: 94 MB
// Date       : 2026-07-09
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    struct Comp{
        bool operator()(const vector<int>& a,const vector<int>& b){
            if(a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        }
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),Comp());
        int n = intervals.size();
        int i = 1;
        int cnt = 0;
        int end = intervals[0][1];
        while(i<n){
            if(intervals[i][1]==end){
                cnt++;
            }
            else if(intervals[i][1]!=end){
                if(intervals[i][0] < end)
                    cnt++;
                else
                    end = intervals[i][1];
            }

            i++;
        }
        
        return cnt;
    }
};