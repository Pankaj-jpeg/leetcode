////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 451. Sort Characters By Frequency
// Difficulty : Medium
// Link       : https://leetcode.com/problems/sort-characters-by-frequency/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: greedy, find and remove max frequency character | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 1 ms  |  Memory: 11 MB
// Date       : 2026-06-13
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char,int> map;

        for(int i =0 ;i<s.length();i++){
            map[s[i]]++;
        }
        string res = "";
        int length = s.length();int cnt =0;
        while(cnt<length){
            pair<char,int> max = {' ',0};
            for(auto itr : map){
                if(max.second < itr.second)
                    max = itr;
            }

            map.erase(max.first);
            for(int i=0;i<max.second;i++){
                res.push_back(max.first);
            }
            cnt+=max.second;
        }
        return res;
    }
};