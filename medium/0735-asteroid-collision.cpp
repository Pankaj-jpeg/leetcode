////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 735. Asteroid Collision
// Difficulty : Medium
// Link       : https://leetcode.com/problems/asteroid-collision/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: stack-based collision detection | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 21.6 MB
// Date       : 2026-07-01
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool coli(int left,int right){
        if(left > 0 && right < 0)
            return true;
        return false;
    }
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int,vector<int>> stk;
        int n = ast.size();
        for(int i=0;i<n;i++){
            if(stk.empty())
                stk.push(ast[i]);
            else{
                int top = stk.top();
                if(coli(top,ast[i])){
                    if(top > abs(ast[i])){
                        continue;
                    }
                    else if(top == abs(ast[i])){
                        stk.pop();continue;
                    }
                    else{
                        while(!stk.empty() && coli(stk.top(),ast[i]) && abs(ast[i]) > stk.top())
                            stk.pop();
                        
                        if(!stk.empty() && coli(stk.top(),ast[i])){
                            if(stk.top() > abs(ast[i])){
                                continue;
                            }
                            else{
                                stk.pop();continue;
                            }
                        }
                        stk.push(ast[i]);
                    }
                }
                else{
                    stk.push(ast[i]);
                }
            }
        }
        vector<int> res(stk.size());
        int i = stk.size()-1;
        while(!stk.empty()){
            res[i] = stk.top();
            stk.pop();
            i--;
        }
        return res;
    }
};