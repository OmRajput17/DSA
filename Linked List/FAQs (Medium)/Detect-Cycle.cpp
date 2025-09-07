#include <bits/stdc++.h>
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

// Optimal using Fast and Slow pointer

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};


"Time Complexity:O(n), where n is the number of nodes in the linked list, as it iterates through the list at most once.
Space Complexity:O(1), as it uses a constant amount of extra space for the slow and fast pointers, regardless of the input size."

// Brute Force using Hashmap

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> mpp;
        ListNode* temp = head;

        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                return true;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }

        return false;
    }
};

"Time Complexity:O(n) in the worst case, where n is the number of nodes in the linked list, due to iterating through the list once.
Space Complexity:O(n) in the worst case, where n is the number of nodes in the linked list, due to storing each node in the hash map."