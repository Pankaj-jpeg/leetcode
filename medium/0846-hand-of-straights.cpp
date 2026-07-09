////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 846. Hand of Straights
// Difficulty : Medium
// Link       : https://leetcode.com/problems/hand-of-straights/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: greedy, iterate through each card and try to form groups | Time: O(n log n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 27 ms  |  Memory: 31.1 MB
// Date       : 2026-07-08
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0)
            return false;

        int no_of_groups = hand.size()/groupSize;

        unordered_map<int,int> m;
        sort(hand.begin(),hand.end());

        for(int i = 0;i<hand.size();i++){
            m[hand[i]]++;
        }


        for(int i = 0;i<hand.size();i++){
            int cnt = 0;
            int j = 0;
            

            int start = hand[i];
            if(m[start] == 0) continue;
            m[start]--;

            for(int j = 0;j<groupSize-1;j++){
                start++;
                if(m[start] == 0)
                    return false;
                m[start]--;
            }
        }

    
        return true;

    }
};