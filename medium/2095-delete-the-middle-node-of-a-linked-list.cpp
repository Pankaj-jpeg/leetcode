////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2095. Delete the Middle Node of a Linked List
// Difficulty : Medium
// Link       : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique with slow and fast pointers to find the node before the middle | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 1 ms  |  Memory: 312 MB
// Date       : 2026-06-15
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};