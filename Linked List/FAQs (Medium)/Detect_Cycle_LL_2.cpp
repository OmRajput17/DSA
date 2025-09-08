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


// Optimal Using Fast and Slow pointer

class Solution {
public:
    ListNode *findStartingPoint(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return 0;
    }
};

"Time Complexity:O(n) in the worst case, where n is the number of nodes in the linked list, due to the two pointer traversal and potential second traversal to find the starting point.
Space Complexity:O(1) because the algorithm uses a constant amount of extra space, regardless of the input size."


// Brute Force using Hashmap

class Solution {
public:
    ListNode *findStartingPoint(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, int> mpp;

        while(temp != NULL){
            if(mpp.count(temp) != 0){
                return temp;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }
        return 0;
    }
};

"Time Complexity:O(n) because it iterates through the linked list once in the worst case.
Space Complexity:O(n) due to the unordered map potentially storing all nodes of the linked list."