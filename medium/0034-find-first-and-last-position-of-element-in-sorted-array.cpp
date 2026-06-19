////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 34. Find First and Last Position of Element in Sorted Array
// Difficulty : Medium
// Link       : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 17.6 MB
// Date       : 2026-06-04
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low  = 0;
        int high = nums.size()-1;
        int mid;

        if(nums.size()==0){
            return {-1,-1};
        }
        if(nums.size()==1 && nums[0]==target){
            return {0,0};
        }
        if(nums.size()==1 && nums[0]!=target){
            return {-1,-1};
        }


        while(low<=high){
            mid = low+(high-low)/2;
            if(target > nums[mid])
                low = mid+1;
            else if(target<nums[mid])
                high = mid-1;
            else
                break;
        }
        if(nums[mid]!=target)
            return {-1,-1};

        int up,lo;
        if(mid-1 >= 0 && nums[mid-1] == target){
            // upper edge
            int l1=0,h1=mid-1,m1;
            while(l1<=h1){
                m1 = l1 + (h1-l1)/2;
                if(target > nums[m1])
                    l1 = m1+1;
                else if(target <= nums[m1])
                    h1 = m1-1;
            }
            up = h1+1;
        }
        else
            up = mid;
        //lower edge
        if(mid+1 <= nums.size()-1 && nums[mid+1] == target){
            int l2 = mid+1,h2 = nums.size()-1,m2;
            while(l2<=h2){
                m2 = l2 + (h2-l2)/2;
                if(target >= nums[m2])
                    l2 = m2+1;
                else
                    h2 = m2-1;
            }
            lo = l2-1;
        }
        else
            lo=mid;
        
        return {up,lo};
    }
};