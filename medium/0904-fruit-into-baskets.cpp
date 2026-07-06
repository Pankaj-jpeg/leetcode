////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 904. Fruit Into Baskets
// Difficulty : Medium
// Link       : https://leetcode.com/problems/fruit-into-baskets/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique with dynamic basket assignment | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 79.7 MB
// Date       : 2026-07-06
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int Max = 0;
        int bsk1 = -1;
        int lat_bsk1;
        int bsk2 = -1;
        int lat_bsk2;
        int l = 0;
        for(int r = 0;r<n;r++){
            if(bsk1 == -1){
                bsk1 = fruits[r];
                lat_bsk1 = r;
            }
            else if (bsk2 == -1 && fruits[r]!=bsk1){
                bsk2 = fruits[r];
                lat_bsk2 = r;
            }
            else{
                if(fruits[r] == bsk1){
                    lat_bsk1 = r;
                }
                else if(fruits[r] == bsk2)
                    lat_bsk2 = r;
                else{
                    l = lat_bsk1 > lat_bsk2 ? lat_bsk2+1 : lat_bsk1+1;
                    if(lat_bsk1 > lat_bsk2){
                        bsk2 = fruits[r];
                        lat_bsk2 = r;
                    }
                    else{
                        bsk1 = fruits[r];
                        lat_bsk1 = r;
                    }
                }
            }

            Max = max(Max,r-l+1);
        }

        return Max;
    }
};