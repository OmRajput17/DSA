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

// Optimal using Fast and SLow pointer

class Solution {
private:
    int findLength(ListNode *slow, ListNode *fast){
        int cnt = 1;
        fast = fast->next;
        while(slow != fast){
            fast = fast->next;
            cnt++;
        }

        return cnt;
    }
public:
    int findLengthOfLoop(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int count = 0;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                return findLength(slow, fast);
            }
        }
        return 0;
    }
};

"Time Complexity:O(n) in the worst case where n is the number of nodes, due to traversing the linked list to find the loop and calculate its length.
Space Complexity:O(1) as it uses a constant amount of extra space for pointers regardless of the input size."


// Brute Force using Hashmap

class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        unordered_map<ListNode*,int> mpp;
        ListNode* temp = head;
        int timer = 1;
        int val;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                val = mpp[temp];

                return timer - val;
            }
            mpp[temp] = timer;
            timer++;
            temp = temp->next;
        }   
        return 0;
    }
};

"Time Complexity:O(n) because in the worst-case scenario, the code iterates through all the nodes in the linked list.
Space Complexity:O(n) due to the unordered map potentially storing all nodes of the linked list in the worst case."