////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 126. Word Ladder II
// Difficulty : Hard
// Link       : https://leetcode.com/problems/word-ladder-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Breadth-First Search (BFS) with backtracking | Time: O(n * 26^L) | Space: O(n + 26^L))
// Time       : 
// Space      : 
// Runtime    : 19 ms  |  Memory: 13.1 MB
// Date       : 2026-08-03
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void backtrack(vector<vector<string>>& ans,vector<string>& path,unordered_map<string,int>& mp,string& word,string& beginWord){
        if(word == beginWord){
            reverse(path.begin(),path.end());
            ans.push_back(path);
            reverse(path.begin(),path.end());
            return;
        }
        for(int i = 0;i<word.size();i++){
            for(char c = 'a';c<='z';c++){
                if(word[i] == c) continue;
                string alt = word;
                alt[i] = c;

                if(mp.count(alt) && mp[alt] == mp[word]-1){
                    path.push_back(alt);
                    backtrack(ans,path,mp,alt,beginWord);
                    path.pop_back();
                }
            }
        }
        
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> vis(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int lvl = 1;
        unordered_map<string,int> mp;
        mp.insert({beginWord,1});
        bool flag = false;
        while(!q.empty()){
            int size = q.size();
            vector<string> toErase;
            for(int i = 0;i<size;i++){
                string curr = q.front();
                q.pop();
                
                if(curr == endWord){
                    flag = true;
                    break;
                }
                
                for(int j = 0;j<curr.size();j++){
                    for(char c = 'a';c<='z';c++){
                        if(curr[j] == c) continue;
                        string alt = curr;
                        alt[j] = c;

                        if(vis.count(alt)){
                            q.push(alt);
                            mp.insert({alt,lvl+1});
                            vis.erase(alt);
                        }
                    }
                }
            }
            if(flag)
                break;
            lvl++;
        }



        vector<vector<string>> ans;
        vector<string> path;
        path.push_back(endWord);
        if(mp.count(endWord))
            backtrack(ans,path,mp,endWord,beginWord);
        return ans;
    }
};