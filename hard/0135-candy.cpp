////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 135. Candy
// Difficulty : Hard
// Link       : https://leetcode.com/problems/candy/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with state machine | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 22.2 MB
// Date       : 2026-07-09
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int candies = 1;
        int up = 0 ,down=0,peak=0;
        for(int i = 1;i<n;i++){
            if(ratings[i] - ratings[i-1] > 0){
                up++;
                peak = up;
                candies+=(up+1);
                down=0;
                
            }
            else if(ratings[i] - ratings[i-1] == 0){
                candies+=1;
                peak = 0;
                up = 0;
                down = 0;
            }
            else{
                down++;up = 0;
                candies+=(down+1) - int(peak>=down);
                
            }
        }


        return candies;

    }
};