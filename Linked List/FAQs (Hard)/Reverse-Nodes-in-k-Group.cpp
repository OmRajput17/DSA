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
**/

class Solution {
private:
    ListNode* reverseLinkedList(ListNode* head){
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
    ListNode* getKthNode(ListNode* temp, int k){
        k--;
        while(temp!=NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp != NULL){
            ListNode* KthNode = getKthNode(temp, k);

            if(KthNode == NULL){
                if(prevNode){
                    prevNode->next = temp;
                }
                break;
            }

            ListNode* nextNode = KthNode->next;
            KthNode->next = NULL;
            reverseLinkedList(temp);
            if(temp == head){
                head = KthNode;
            }
            else{
                prevNode->next = KthNode;
            }

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};

"Time Complexity:O(n), where n is the number of nodes in the linked list, due to iterating through the list and reversing sublists.
Space Complexity:O(1), because the algorithm uses constant extra space regardless of the input size."