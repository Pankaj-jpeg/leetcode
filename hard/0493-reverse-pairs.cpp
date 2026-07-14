////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 493. Reverse Pairs
// Difficulty : Hard
// Link       : https://leetcode.com/problems/reverse-pairs/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: divide and conquer, merge sort | Time: O(n log n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 507 ms  |  Memory: 243.5 MB
// Date       : 2026-07-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int pairs(vector<int>& nums,int low,int mid,int high){
        int cnt = 0;
        int i = low;
        int j = mid+1;
        while(j<=high && i<=mid){
            if(nums[i] > (long long)2*nums[j]){
                cnt+=(mid-i+1);
                j++;
            }
            else{
                i++;
            }
            
        }
        return cnt;
    }
    int merge(vector<int>& nums,int low,int mid,int high){
        vector<int> merged;
        int i = low;
        int j = mid+1;
        int pair = pairs(nums,low,mid,high);
        while(i<=mid && j<=high){
            if(nums[i] <= nums[j]){
                merged.push_back(nums[i]);
                i++;
            }
            else{
                merged.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            merged.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            merged.push_back(nums[j]);
            j++;
        }
        int k = low;
        for(int i = 0;i<merged.size();i++){
            nums[k] = merged[i];k++;
        }
        return pair;
    }
    int mergeSort(vector<int>&nums,int low,int high){
        if(low >= high)
            return 0;

        int mid = low + (high - low)/2;

        return  mergeSort(nums,low,mid) + mergeSort(nums,mid+1,high) + merge(nums,low,mid,high);
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};