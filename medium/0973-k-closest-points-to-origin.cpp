////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 973. K Closest Points to Origin
// Difficulty : Medium
// Link       : https://leetcode.com/problems/k-closest-points-to-origin/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: QuickSelect with partitioning | Time: O(n) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 235 ms  |  Memory: 64.9 MB
// Date       : 2026-07-07
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int dist(vector<int>& a){
        return (a[0]*a[0] + a[1]*a[1]);
    }
    int partition(vector<vector<int>>& points,int low,int high,int pivot){
        if(low >= high){
            return high;
        }
        int key = dist(points[pivot]);
        swap(points[low],points[pivot]);
        int k = low;
        for(int j = low+1;j<=high;j++){
            if(dist(points[j]) < key){
                k++;
                swap(points[j],points[k]);
            }
        }
        swap(points[low],points[k]);
        return k;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        int low = 0;
        int high = n-1;
        int p;
        while(true){
            int pivot = low + rand()%(high-low+1);
            p = partition(points,low,high,pivot);
            if((p+1) == k) break;
            else if((p+1) < k)
                low = p+1;
            else
                high = p-1;

            if(low == high){
                p = low;
                break;
            }
        }

        vector<vector<int>> res;

        for(int i = 0;i<k;i++){
            res.push_back(points[i]);
        }

        return res;
    }
};