#include<bits/stdc++.h>

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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->next == val){
            head = head->next;
        }
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
            if(temp->next->val == val){
                temp->next = temp->next->next;
            }else{
                temp = temp->next;
            }
        }

        return head;
    }
};

"The time complexity of the given code is O(n), where n is the number of nodes in the linked list. This is because the algorithm traverses the list at most once, checking each node's value and removing nodes as needed.

The space complexity is O(1), meaning it uses constant extra space. The algorithm modifies the list in place without requiring additional data structures proportional to the size of the input list. It only uses a few pointers for traversal and manipulation."