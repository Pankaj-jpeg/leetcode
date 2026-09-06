////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3876. Construct Uniform Parity Array II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/construct-uniform-parity-array-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 166 MB
// Date       : 2026-09-03
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallest = INT_MAX;
        bool flag = true;
        for(int i = 0;i<nums1.size();i++){
            if(nums1[i]%2 != 0){
                flag = false;
            }
            smallest = min(smallest,nums1[i]);
        }
        if(flag)
            return true;

        return smallest%2 != 0;
        
        

    }
};