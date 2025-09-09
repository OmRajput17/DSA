#include<bits/stdc++.h>
using namespace std;

/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        int len = 1;
        while(temp->next != NULL){
            ++len;
            temp = temp->next;
        }

        // Linking tail to head
        temp->next = head;

        k = k % len;

        int end = len - k;
        
        while(end > 0){
            temp = temp->next;
            end--;
        }

        head = temp->next;
        temp->next = NULL;

        return head; 
    }
};

"Time Complexity:O(n) because the code iterates through the linked list once to find the length and then iterates again to find the new head, where n is the number of nodes in the linked list.
Space Complexity:O(1) as it uses a constant amount of extra space regardless of the size of the linked list."