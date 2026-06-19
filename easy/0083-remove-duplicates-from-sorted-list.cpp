////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 83. Remove Duplicates from Sorted List
// Difficulty : Easy
// Link       : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 16.1 MB
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
        ListNode* curr = head;
        ListNode* next = curr;
        
        if(head == NULL || head->next == NULL)
            return head;
        while(curr!=NULL){
            next = curr->next;
            if(prev && prev->val == curr->val){
                prev->next = next;
            }
            else{
                prev = curr;
            }
            curr=next;
        }

        return head;
    }
};