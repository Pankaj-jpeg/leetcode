////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 160. Intersection of Two Linked Lists
// Difficulty : Easy
// Link       : https://leetcode.com/problems/intersection-of-two-linked-lists/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique with length adjustment | Time: O(n + m) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 63 ms  |  Memory: 24 MB
// Date       : 2026-06-16
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* itr1 = headA;
        ListNode* itr2 = headB;
        while(itr1!=NULL){
            lenA++;
            itr1 = itr1->next;
        }
        while(itr2!=NULL){
            lenB++;
            itr2 = itr2->next;
        }

        int diff = lenA>lenB?lenA-lenB:lenB-lenA;
        itr1 = headA;
        itr2 = headB;
        if(lenA>lenB){
            while(diff>0){
                itr1 = itr1->next;
                diff--;
            }
        }
        else if (lenA < lenB){
            while(diff>0){
                itr2 = itr2->next;
                diff--;
            }
        }
        
        while(itr1!=NULL && itr2!=NULL){
            if(itr1==itr2){
                return itr1;
            }
            itr1 = itr1->next;
            itr2 = itr2->next;
        }

        return NULL;
    }
};