////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 282. Expression Add Operators
// Difficulty : Hard
// Link       : https://leetcode.com/problems/expression-add-operators/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: depth-first search with backtracking | Time: O(4^n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 391 ms  |  Memory: 92.9 MB
// Date       : 2026-06-22
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<string> res;
    void recursive(string path,const string& num,long result,const int& target,int idx,long prev_num){
        if(idx == num.length()){
            if(result==target) {
                res.push_back(path);
                return;
            }
        }   
        string str;long n = 0;
        for(int i = idx;i<num.length();i++){
            if(i>idx && num[idx] == '0') return;
            str+=num[i];
            n = 10*n + (num[i]-'0');
            if(idx==0){  
                recursive(path+str,num,n,target,i+1,n);
            }
            else{
                recursive(path+'+'+str,num,result+n,target,i+1,n); 
                recursive(path+'-'+str,num,result-n,target,i+1,-n);
                recursive(path+'*'+str,num,result - prev_num + prev_num*n,target,i+1,prev_num*n);

            }
        }

    }

    vector<string> addOperators(string num, int target) {
        string path = "";
        recursive(path,num,0,target,0,0);
        return res;
    }
};