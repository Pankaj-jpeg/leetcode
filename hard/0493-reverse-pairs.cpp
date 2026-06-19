////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 493. Reverse Pairs
// Difficulty : Hard
// Link       : https://leetcode.com/problems/reverse-pairs/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 355 ms  |  Memory: 193 MB
// Date       : 2026-06-03
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void merge(vector<int>& nums,int low,int mid,int high){
        if(nums[mid] <= nums[mid+1]){
            return;
        }
        vector<int> res;
        int start = low;
        int start2 = mid+1;
        while(start <= mid && start2 <= high){
            if(nums[start] <= nums[start2]){
                res.push_back(nums[start]);
                start++;
            }
            else{
                res.push_back(nums[start2]);
                start2++;
            }
        }
        while(start <= mid){
            res.push_back(nums[start]);
            start++;
        }
        while(start2<=high){
            res.push_back(nums[start2]);
            start2++;
        }
        int i=low;
        for(int num:res){
            nums[i] = num;
            i++;
        }
    }
    int cnt=0;
    void count(vector<int>& nums,int low,int mid,int high){
        int right = mid+1;
        
        for(int i = low;i<=mid;i++){
            while(right<=high && (long long)nums[i] > 2LL*nums[right]){
                right++;
            }
            cnt+= right-(mid+1);
        }
    }
    void mergesort(vector<int>& nums,int low,int high){
        if(low >= high){
            return ;
        }
        int mid = (low + high)/2;

        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        count(nums,low,mid,high);
        merge(nums,low,mid,high);
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return cnt;
    }
};