#include <bits/stdc++.h>
using namespace std;

/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode * deleteHead(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }

        ListNode* back = head;
        head = head->next;
        head -> prev = nullptr;
        back -> next = nullptr;
        delete(back);

        return head;
    }
};

"Time Complexity: O(1) because removing the head node from a doubly linked list is a constant-time operation. It's independent of the list's size, as it involves updating references to the head and the new head.

Space Complexity: O(1) as no extra space is used."