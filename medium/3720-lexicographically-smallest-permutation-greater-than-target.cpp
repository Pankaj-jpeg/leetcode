////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3720. Lexicographically Smallest Permutation Greater Than Target
// Difficulty : Medium
// Link       : https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 11.3 MB
// Date       : 2026-08-27
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> hash(26,0);
        for(auto it : s){
            hash[it-'a']++;
        }
        int n = s.size();

        for(int i = n-1;i>=0;i--){
            vector<int> remain = hash;

            bool possible = true;

            for(int j = 0;j<i;j++){
                int x = target[j] - 'a';
                if(remain[x] == 0){
                    possible = false;
                    break;
                }
                remain[x]--;
            }
            if(!possible)
                continue;
            
            for(int k = (target[i] - 'a') + 1 ;k<26;k++){
                if(remain[k] == 0)
                    continue;
                
                string res = target.substr(0,i);
                res.push_back(k + 'a');
                remain[k]--;

                for(int it = 0;it<26;it++){
                    res.append(remain[it],it + 'a');
                }
                return res;
            }
        }

        return "";
        
    }
};