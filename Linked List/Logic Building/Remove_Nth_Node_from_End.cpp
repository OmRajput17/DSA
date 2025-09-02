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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }

        int cnt = 0;
        ListNode* temp = head;

        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }

        if(cnt == n){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int res = cnt - n;
        temp = head;

        while(temp!=NULL){
            res--;
            if(res==0){
                break;
            }
            temp = temp->next;
        }
        ListNode* deleteNode = temp -> next;
        temp->next = temp->next->next;
        delete deleteNode;
        return head;
    }
};

"Time Complexity:O(n) because the code iterates through the linked list twice, once to calculate the length and another to find the node to delete.
Space Complexity:O(1) because the code uses a constant amount of extra space, regardless of the size of the linked list"