////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 733. Flood Fill
// Difficulty : Easy
// Link       : https://leetcode.com/problems/flood-fill/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Breadth-First Search (BFS) | Time: O(m*n) | Space: O(m*n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 18.2 MB
// Date       : 2026-07-28
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        
        int original = image[sr][sc];
        if(original == color) return image;
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;

        while(!q.empty()){
            int size = q.size();

            for(int k = 0;k<size;k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                //up
                if(isValid(i-1,j,m,n) && image[i-1][j] == original){
                    q.push({i-1,j});
                    image[i-1][j] = color;
                }

                //down
                if(isValid(i+1,j,m,n) && image[i+1][j] == original){
                    q.push({i+1,j});
                    image[i+1][j] = color;
                }

                //right
                if(isValid(i,j+1,m,n) && image[i][j+1] == original){
                    q.push({i,j+1});
                    image[i][j+1] = color;
                }


                //left
                if(isValid(i,j-1,m,n) && image[i][j-1] == original){
                    q.push({i,j-1});
                    image[i][j-1] = color;
                }

            }
        }


        return image;
    }
};