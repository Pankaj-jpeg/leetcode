////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3964. Minimum Lights to Illuminate a Road
// Difficulty : Medium
// Link       : https://leetcode.com/problems/minimum-lights-to-illuminate-a-road/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: dynamic programming with two passes | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 39 ms  |  Memory: 277.9 MB
// Date       : 2026-06-20
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> illu(n,false);int il = 0;int next_false = 0;
        for(int i =0;i<n;i++){
            int v = lights[i];
            if(v>0){
                il = 1;
                next_false = max(next_false,min(n-1,i+v)+1);
            }
            if(i == next_false) il = 0;
            illu[i] = max(illu[i],il);
        }
        for(int i =n-1;i>=0;i--){
            int v = lights[i];
            if(v>0){
                il = 1;
                next_false = min(next_false,max(0,i-v)-1);
            }
            if(i == next_false) il = 0;
            illu[i] = max(illu[i],il);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i<n-2 && illu[i] == 0 && illu[i+2] == 0){
                cnt++;
                illu[i]=1;illu[i+1]=1;illu[i+2]=1;
            }
            else if(illu[i] == 0){
                cnt++;
                illu[i] = 1;
                if(i<n-1)
                    illu[i+1] = 1;
            }
        }
        return cnt;
    }
};