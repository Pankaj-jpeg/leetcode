////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 127. Word Ladder
// Difficulty : Hard
// Link       : https://leetcode.com/problems/word-ladder/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Breadth-First Search (BFS) with word transformation | Time: O(n * 26^L) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 64 ms  |  Memory: 19.9 MB
// Date       : 2026-08-03
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool possibleNext(string s1,string s2){
        int cnt = 0;
        for(int i = 0;i<s1.size();i++){
            if(s1[i] != s2[i])
                cnt++;
            if(cnt > 1)
                return false;
        }
        return cnt == 1;
    }
   
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int k = 1;
        int n = wordList.size();
        
        bool contains = false;
        unordered_set<string> vis;
        for(int i = 0;i<n;i++){
            if(wordList[i] == endWord)
                contains = true;
            
            vis.insert(wordList[i]);
        }
        if(!contains)
            return 0;

        
        
        queue<string> q;
        q.push(beginWord);
        vis.erase(beginWord);
        while(!q.empty()){
            int size = q.size();
            for(int j = 0;j<size;j++){
                string curr = q.front();
                if(curr == endWord){
                    return k;
                }
                q.pop();
                for(int i = 0;i<curr.size();i++){
                    for(char c = 'a';c<='z';c++){
                        if(curr[i] == c) continue;
                        string alt = curr;
                        alt[i] = c;
                        if(vis.find(alt)!=vis.end()){
                            q.push(alt);
                            vis.erase(alt);
                        }
                    }
                }
            }
            k++;
        }

        return 0;
    }
};