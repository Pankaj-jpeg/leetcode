////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2521. Distinct Prime Factors of Product of Array
// Difficulty : Medium
// Link       : https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: prime factorization for each number in the array | Time: O(n*sqrt(n)) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 15 ms  |  Memory: 22.8 MB
// Date       : 2026-06-24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> set;
        for(int i = 0;i<nums.size();i++){
            for(int j =2 ; j<= sqrt(nums[i]) ; j++){
                if(nums[i]%j == 0){
                    set.insert(j);
                    while(nums[i]%j == 0)
                        nums[i]/=j;
                }
            }
            if(nums[i] > 1)
                set.insert(nums[i]);
        }
        return set.size();
    }
};