////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3986. Number of Elapsed Seconds Between Two Times
// Difficulty : Easy
// Link       : https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: manual time conversion | Time: O(1) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 8.9 MB
// Date       : 2026-07-12
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int end_sec = endTime[6]*10 + endTime[7];
        int end_min = endTime[3]*10 + endTime[4];
        int end_hou = endTime[0]*10 + endTime[1];

        int st_sec = startTime[6]*10 + startTime[7];
        int st_min = startTime[3]*10 + startTime[4];
        int st_hou = startTime[0]*10 + startTime[1];

        bool flag = false;
        int res_sec = 0;
        if(end_sec>=st_sec)
            res_sec += end_sec - st_sec;
        else{
            res_sec += end_sec + 60 - st_sec;
            flag = true;
        }

        if(end_min >= end_sec){
            res_sec += 60*(end_min - st_min - flag);
            flag = false;
        }
        else{
            res_sec += 60*(end_min + 60 - st_min - flag);
            flag = true;
        }
        res_sec+= 3600*(end_hou - st_hou - flag);

        return res_sec;
        
    }
};