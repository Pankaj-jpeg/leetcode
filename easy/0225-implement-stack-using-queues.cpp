////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 225. Implement Stack using Queues
// Difficulty : Easy
// Link       : https://leetcode.com/problems/implement-stack-using-queues/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two queues, transfer elements between them | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 10.1 MB
// Date       : 2026-06-28
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MyStack {
public:
    int t;
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        t = -1;
    }
    
    void push(int x) {
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }   
    }
    
    int pop() {
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */