////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 128. Longest Consecutive Sequence
// Difficulty : Medium
// Link       : https://leetcode.com/problems/longest-consecutive-sequence/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: hash set, check for consecutive sequence | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 75 ms  |  Memory: 89 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int i = 0;i<nums.size();i++){
            set.insert({nums[i]});
        }
        int curr = 0;
        int Max = 0;
        for(auto it : set){
            if(set.find(it-1) == set.end()){
                curr = 1;
                int curr_val = it + 1;
                while(set.find(curr_val)!=set.end()){
                    curr++;
                    curr_val++;
                }
                Max = max(Max,curr);
            }
        }

        

        return Max;
        
    }
};