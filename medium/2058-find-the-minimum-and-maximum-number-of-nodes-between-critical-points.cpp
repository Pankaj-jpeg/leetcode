////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// Difficulty : Medium
// Link       : https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 8 ms  |  Memory: 124.6 MB
// Date       : 2026-09-01
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return {-1,-1};
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        int i = 1;

        int first = -1;
        int last = -1;
        int p = -1;
        int Min = INT_MAX;
        while(curr->next!=nullptr){
            if((prev->val < curr->val && curr->val > curr->next->val)  ||  (prev->val > curr->val && curr->val < curr->next->val)){
                if(first == -1)
                    first = i;
                if(p!=-1)
                    Min = min(Min,i-p);
                last = i;
                p = i;
            }
            prev = curr;
            curr = curr->next;

            i++;
        }
        int Max = last - first;
        if(first == last || first == -1)
            return {-1,-1};
        return {Min,Max};

    }
};