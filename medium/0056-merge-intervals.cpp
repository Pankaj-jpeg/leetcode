////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 56. Merge Intervals
// Difficulty : Medium
// Link       : https://leetcode.com/problems/merge-intervals/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique with interval merging | Time: O(n log n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 2 ms  |  Memory: 23.9 MB
// Date       : 2026-06-01
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
    //S1<=S2 S2<=E1 E1<=E2
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int i=0;int j;
        while(i<n){
           int start = intervals[i][0];
           int end = intervals[i][1];
           j = i+1;
           while(j<n && start<=intervals[j][0] && intervals[j][0] <= end ){
                if(end<=intervals[j][1]){
                    end = intervals[j][1];
                    j++;
                }
                else if(end>=intervals[j][1])
                    j++;
           }
           res.push_back({start,end});
           i=j;
        }
        
        return res;
    }
};