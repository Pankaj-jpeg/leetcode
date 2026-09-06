////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1048. Longest String Chain
// Difficulty : Medium
// Link       : https://leetcode.com/problems/longest-string-chain/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 43 ms  |  Memory: 24.1 MB
// Date       : 2026-08-31
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    struct Comp{
        bool operator()(const string& a,const string& b){
            return a.size() < b.size();
        }
    };
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),Comp());
        int n = words.size();

        vector<int> dp(n,1);
        unordered_map<string,int> m;
        int Max = 0;
        for(int i = 0;i<n;i++){
            string s = words[i];
            for(int j = 0;j < (int)s.size();j++){
                char c = s[j];
                string temp;
                if(j == 0){
                    temp = s.substr(1,s.size()-1);
                }
                else if(j == s.size()-1){
                    temp = s.substr(0,s.size()-1);
                }
                else
                    temp = s.substr(0,j) + s.substr(j+1,s.size()-(j+1));

                
                if(m.find(temp) == m.end())
                    continue;
                
                int prev = m[temp];

                dp[i] = max(dp[i],prev+1);
            }
            m.insert({words[i],dp[i]});
            Max=max(Max,dp[i]);
        }

        return Max;

    }
};