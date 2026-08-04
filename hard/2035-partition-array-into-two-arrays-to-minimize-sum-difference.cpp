////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2035. Partition Array Into Two Arrays to Minimize Sum Difference
// Difficulty : Hard
// Link       : https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: bitmask, dynamic programming | Time: O(n*2^n) | Space: O(n*2^n))
// Time       : 
// Space      : 
// Runtime    : 376 ms  |  Memory: 73.3 MB
// Date       : 2026-08-04
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int N = n/2;

        int sum = 0;
        for(auto it: nums)
            sum+=it;


        vector<vector<int>> left(N+1),right(N+1);

        
        for(int i = 0;i<(1<<N);i++){
            int cnt = 0;
            int l = 0;
            int r = 0;
            for(int j= 0;j<N;j++){
                if(i&(1<<j)){
                    cnt++;
                    l+=nums[j];
                    r+=nums[j+N];
                }
            }

            left[cnt].push_back(l);
            right[cnt].push_back(r);
        }


        for(int i = 0;i<N+1;i++){
            sort(right[i].begin(),right[i].end());
        }

        int Min = INT_MAX;

        for(int k = 0;k<N;k++){
            for(auto s : left[k]){
                int right_sum = (sum/2) - s;
                int x = 0;
                auto it = lower_bound(right[N-k].begin(),right[N-k].end(),right_sum);


                if(it != right[N-k].end()){
                    x = *it;
                    Min = min(abs(sum - 2*(s+x)),Min);
                }
                if( it != right[N-k].begin()){
                    it--;
                    x = *it;
                    Min = min(abs(sum - 2*(s+x)),Min);
                }
            }
        }

        
        return Min;

    }
};