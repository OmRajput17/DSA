#include<bits/stdc++.h>
using namespace std;

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        while(temp1 && temp2){
            swap(temp1->val, temp2->val);
            temp1 = temp2->next;
            if(temp1){
                temp2 = temp1->next;
            }
        }
        return head;
    }
};

// TC = O(N)
// SC = O(1)