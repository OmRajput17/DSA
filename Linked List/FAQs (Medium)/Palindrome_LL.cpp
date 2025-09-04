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
// Without using any External Data Structure

class Solution {
private:
    ListNode* reverse(ListNode* head){
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
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        while(second != NULL){
            if(first->val != second->val){
                reverse(newHead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        reverse(newHead);

        return true;
    }
};
"Time Complexity: O(2xN) The algorithm involves traversing the linked list twice. The first traversal finds the middle and reverses the second half, while the second traversal compares elements from both halves. Since each traversal covers N/2 elements, the total time complexity is O(N/2 + N/2 + N/2 + N/2), which simplifies to O(2N), ultimately reducing to O(N).

Space Complexity: O(1) This approach uses a constant amount of additional space, regardless of the linked list's size. It does not require any extra data structures that depend on the input size, resulting in a space complexity of O(1)."


// Using Stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            if(temp->val != st.top()){
                return false;
            }
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};