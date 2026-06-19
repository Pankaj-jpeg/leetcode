////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 234. Palindrome Linked List
// Difficulty : Easy
// Link       : https://leetcode.com/problems/palindrome-linked-list/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: reversing the second half of the linked list | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 1 ms  |  Memory: 114.2 MB
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
    bool isPalindrome(ListNode* head) {
        int len =0;
        ListNode* itr=head;
        while(itr!=NULL){
            len++;
            itr=itr->next;
        }
        int idx;
        idx = len/2;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = curr;
        while(idx>0){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            idx--;
        }

        if(len%2 != 0){
           curr = curr->next;
        }
        while(prev!=NULL && curr!=NULL){
            if(prev->val != curr->val)
                return false;
            prev = prev->next;
            curr = curr->next;
        }

        return true;


    }
};