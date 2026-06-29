////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 232. Implement Queue using Stacks
// Difficulty : Easy
// Link       : https://leetcode.com/problems/implement-queue-using-stacks/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two stacks, transfer elements from one stack to the other for efficient popping | Time: O(1) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 10.3 MB
// Date       : 2026-06-28
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */