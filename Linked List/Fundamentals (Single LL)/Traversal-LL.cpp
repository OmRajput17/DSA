#include<bits/stdc++.h>

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
    vector<int> LLTraversal(ListNode *head) {
        ListNode* temp = head;
        vector<int> ans;
        while(temp){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        return ans;
    }
};

"Time Complexity:O(n), where n is the number of nodes in the linked list.
Space Complexity:O(n), where n is the number of nodes in the linked list to store the list in the answer vector."