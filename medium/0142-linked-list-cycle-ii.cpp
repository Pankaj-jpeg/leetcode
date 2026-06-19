////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 142. Linked List Cycle II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/linked-list-cycle-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Floyd's Tortoise and Hare algorithm (cycle detection) | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 11.4 MB
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        if(head == NULL || head->next == NULL)
            return NULL;

        bool flag = false;
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                flag = true;
                break;
            }
        }
        if(!flag)
            return NULL;

        ListNode* curr = head;
        while(curr!=slow){
            curr = curr->next;
            slow = slow->next;
        }

        return curr;

        
    }
};