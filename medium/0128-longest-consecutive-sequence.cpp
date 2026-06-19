////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 128. Longest Consecutive Sequence
// Difficulty : Medium
// Link       : https://leetcode.com/problems/longest-consecutive-sequence/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: hash set, iterate through each number and check for consecutive sequence | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 83 ms  |  Memory: 88.9 MB
// Date       : 2026-05-25
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> map;
        int max=0;int cnt;
        for(int i =0;i<nums.size();i++){
            map.insert({nums[i]});
        }

        for(auto num : map){
            if(map.find(num-1)==map.end()){
                cnt=1;
                auto x=num;
                while(map.find(x+1)!=map.end()){
                    cnt++;
                    x++;
                }
                if(cnt>max)
                    max=cnt;
            }
        }
        return max;
    }
};