////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2. Add Two Numbers
// Difficulty : Medium
// Link       : https://leetcode.com/problems/add-two-numbers/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: iterative, linked list traversal | Time: O(max(n, m)) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 76.5 MB
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* itr1 = l1;
        ListNode* itr2 = l2;ListNode* last;


        while(itr1!=NULL || itr2!=NULL){
            if(itr1 && itr2){
                itr1->val = itr1->val + itr2->val + carry;
                if(itr1->val > 9){
                    carry = 1;
                    itr1->val = itr1->val%10;
                }
                else
                    carry = 0;
                
                if(itr1->next == NULL && itr2->next !=NULL){
                    itr1->next = itr2->next;
                    itr2->next = NULL;
                }
                if(itr1->next!=NULL)
                    itr1 = itr1->next;
                else
                    break;
                itr2 = itr2->next;
            }
            else if(itr1){
                itr1 -> val = itr1->val + carry;
                if(itr1->val > 9){
                    carry = 1;
                    itr1->val = itr1->val%10;
                }
                else
                    carry = 0;


                if(itr1->next!=NULL)
                    itr1 = itr1->next;
                else
                    break;
            }
        }


        if(carry!=0){
            itr1->next = new ListNode(carry);
        }
       return l1;
    }
};