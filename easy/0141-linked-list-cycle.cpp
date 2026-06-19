////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 141. Linked List Cycle
// Difficulty : Easy
// Link       : https://leetcode.com/problems/linked-list-cycle/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Floyd's Tortoise and Hare algorithm | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 8 ms  |  Memory: 11.9 MB
// Date       : 2026-06-15
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        if(head==NULL || head->next == NULL)
            return false;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }

        return false;
        
    }
};