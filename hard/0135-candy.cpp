////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 135. Candy
// Difficulty : Hard
// Link       : https://leetcode.com/problems/candy/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with separate counters for up and down sequences | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 22.1 MB
// Date       : 2026-08-08
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int candies = 1;
        int up = 1;
        int down = 1;
        int peak = 1;
        for(int i = 1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                candies+=(up+1);
                up++;
                peak = up;
                down = 1;
            }
            else if (ratings[i] == ratings[i-1]){
                candies+=1;
                peak = 1;
                up = 1;
                down = 1;
            }
            else{
                candies+=(down);
                if(down >= peak)
                    candies+=1;
                down++;
                up = 1;
                
            }
        }

        return candies;

    }
};