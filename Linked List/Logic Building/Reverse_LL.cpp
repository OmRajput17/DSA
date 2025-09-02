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

// Without using Xtra Space
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* back = nullptr;
        
        while(temp != NULL){
            ListNode* front = temp -> next;
            temp -> next = back;
            back = temp;
            temp = front;
        }

        return back;
    }
};

"Time Complexity:O(n), where n is the number of nodes in the linked list.
Space Complexity:O(1), as the algorithm uses a constant amount of extra space."


//  Using STACK
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};