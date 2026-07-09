////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 860. Lemonade Change
// Difficulty : Easy
// Link       : https://leetcode.com/problems/lemonade-change/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic counting of available bills | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 87.3 MB
// Date       : 2026-07-08
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(3,0);
        //change[0] ----> $5 bills
        //change[1] ----> $10 bills
        //change[2] ----> $20 bills
        int n = bills.size();

        for(int i = 0;i<n;i++){
            int total_return = bills[i] - 5;


            bills[i] == 5 ? change[0]++ : (bills[i] == 10 ? change[1]++ : change[2]++);

            if(total_return == 0)
                continue;
            else if(total_return == 5){
                if(change[0] > 0)
                    change[0]--;
                else
                    return false;
            }
            else{
                if(change[1] > 0 && change[0] > 0){
                    change[1]--;
                    change[0]--;
                }
                else if (change[0] >= 3){
                    change[0]-=3;
                }
                else
                    return false;
            }
        }


        return true;
    }
};