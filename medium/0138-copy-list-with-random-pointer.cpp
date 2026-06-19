////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 138. Copy List with Random Pointer
// Difficulty : Medium
// Link       : https://leetcode.com/problems/copy-list-with-random-pointer/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: hash table to store old nodes and their corresponding new nodes, then update new nodes' random pointers | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 6 ms  |  Memory: 15.1 MB
// Date       : 2026-06-17
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = NULL;
        if(head == NULL)
            return newHead;
        unordered_map <Node*,Node*> map;
        Node* itr = head;
        Node* curr;
        Node* prev;
        while(itr!=NULL){
            curr = new Node(itr->val);
            map.insert({itr,curr});
            if(newHead==NULL){
                newHead = curr;
                prev = curr;
            }
            else{
                prev->next = curr;
                prev = curr;
            }
            itr = itr->next;
        }

        itr = head;Node* current;Node* current_random;
        while(itr!=NULL){
            current = map.find(itr)->second;
            if(itr->random!=NULL){
                current_random = map.find(itr->random)->second;
                current->random = current_random;
            }
            else
                current->random = NULL;
            itr = itr->next;   
        }
        return newHead;   
    }
};