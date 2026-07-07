////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 621. Task Scheduler
// Difficulty : Medium
// Link       : https://leetcode.com/problems/task-scheduler/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: frequency counting and idle intervals | Time: O(n) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 38.3 MB
// Date       : 2026-07-07
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int k = tasks.size();
        vector<int>freq(26,0);
        int Max_freq = 0;
        for(int i = 0;i<k;i++){
            freq[tasks[i]-'A']++;
            Max_freq = max(Max_freq,freq[tasks[i]-'A']);
        }
        int cnt = 0;
        for(int i = 0;i<26;i++){
            if(freq[i] == Max_freq)
                cnt++;
        }
        int intervals = (Max_freq-1)*(n+1) + cnt;
        return max(k,intervals);
    }
};