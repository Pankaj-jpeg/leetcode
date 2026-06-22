////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3968. Maximum Manhattan Distance After All Moves
// Difficulty : Medium
// Link       : https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic state tracking | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 20 ms  |  Memory: 22.2 MB
// Date       : 2026-06-21
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxDistance(string moves) {
        bool is_up = false;bool is_right = false;
        int cnt_up=0;int cnt_dn =0;int cnt_r=0;int cnt_l=0;
        for(auto itr:moves){
            if(itr == 'U')cnt_up++;
            if(itr == 'D')cnt_dn++;
            if(itr == 'L')cnt_l++;
            if(itr == 'R')cnt_r++;
        }
        is_up = cnt_up > cnt_dn;
        is_right = cnt_r > cnt_l;
        int dist = 0;
        for(auto itr : moves){
            if(is_up && is_right){
                if(itr == 'D'|| itr == 'L')dist--;
                else dist++;
            }
            else if(is_up && !is_right){
                if(itr == 'D' || itr == 'R')dist--;
                else dist++;
            }
            else if(!is_up && is_right){
                if(itr == 'U' || itr == 'L')dist--;
                else dist++;
            }
            else{
                if(itr == 'U' || itr == 'R')dist--;
                else dist++;
            }
        }

        return dist;
    }
};