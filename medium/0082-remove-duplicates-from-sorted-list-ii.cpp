////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 82. Remove Duplicates from Sorted List II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: iterative, maintaining a new head and previous node | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 15.7 MB
// Date       : 2026-06-16
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;ListNode* newHead=NULL;
        ListNode* next = curr;
        
        if(head == NULL || head->next == NULL)
            return head;
        while(curr!=NULL){
            next = curr->next;
            if(next && curr->val!=next->val){
                if(prev)
                    prev->next = curr;
                prev = curr;
                curr = next;
                prev->next = NULL;
            }
            else if (next && curr->val == next->val){
                int temp = curr->val;
                while(curr && curr->val == temp){
                    curr = curr->next;
                }
                next = curr;
            }
            if(newHead == NULL && prev!=NULL)
                newHead = prev;
            if(prev && curr && !next && curr->val!=prev->val){
                prev->next = curr;
                curr = curr->next;
            }
            else if(!prev && curr && !next){
                prev = curr;
                newHead = prev;
                curr = curr->next;
            }
                
        }

        return newHead;
    }
};