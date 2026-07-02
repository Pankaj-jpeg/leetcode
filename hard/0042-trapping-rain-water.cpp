////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 42. Trapping Rain Water
// Difficulty : Hard
// Link       : https://leetcode.com/problems/trapping-rain-water/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique, maintaining max left and right heights | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 26 MB
// Date       : 2026-07-01
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0;
        int rightMax = 0;
        int total = 0;
        int start = 0;
        int end = n-1;
        while(start<end){
            leftMax = max(leftMax,height[start]);
            rightMax = max(rightMax,height[end]);

            if(leftMax < rightMax){
                total += leftMax - height[start];
                start++;
            }
            else{
                total += rightMax - height[end];
                end--;
            }
        }
        
        return total;
 
    }
};