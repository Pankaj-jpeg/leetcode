////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 430. Flatten a Multilevel Doubly Linked List
// Difficulty : Medium
// Link       : https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: recursive DFS with in-place flattening | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 11.6 MB
// Date       : 2026-06-17
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* itr = head;
        while(itr!=NULL){
            if(itr->child){
                Node* dummy = flatten(itr->child);
                while(dummy->next!=NULL){
                    dummy = dummy->next;
                }
                Node* next = itr->next;
                //mapping
                dummy->next = itr->next;
                if(next)
                    itr->next->prev = dummy;

                itr->next = itr->child;
                itr->child->prev = itr;
                //setting NULL
                itr->child = NULL;

                //next
                itr = next;
            }
            else{
                itr = itr->next;
                continue;
            }
        }
        return head;
    }
};