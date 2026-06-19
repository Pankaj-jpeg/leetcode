////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 19. Remove Nth Node From End of List
// Difficulty : Medium
// Link       : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique with slow and fast pointers | Time: O(L) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 15 MB
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        if(!fast){
            return head->next;
        }
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return head;

    }
};