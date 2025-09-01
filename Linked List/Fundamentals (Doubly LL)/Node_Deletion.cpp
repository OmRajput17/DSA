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
    void deleteGivenNode(ListNode* node) {
        ListNode* back = node -> prev;
        ListNode* front = node -> next;
        
        if(front == NULL){
            back->next = nullptr;
            node -> prev = nullptr;
            free(node);
            return;
        }

        back->next = front;
        front -> prev = back;

        node->prev = node->next = nullptr;
        free(node);
    }
};

"Time Complexity: O(1) as it only involves updating references and is independent of the list’s length.
Space Complexity: O(1) as no extra space is used."