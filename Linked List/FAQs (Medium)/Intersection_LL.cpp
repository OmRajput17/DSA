#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
**/

// Optimal Solution
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }

        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
            if(t1 == t2) return t1;

            if(t1 == NULL){
                t1 = headB;
            }
            if(t2 == NULL){
                t2 = headA;
            }
        }
        return t1;
    }
};



// Without using Extra Space

class Solution {
private:
    ListNode* collisionPoint(ListNode* temp1, ListNode* temp2, int d){
        for(int i = 0; i<d; i++){
            temp2 = temp2->next;
        }
        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int n1 = 0, n2 = 0;

        while(t1 != NULL){
            n1++;
            t1=t1->next;
        }

        while(t2 != NULL){
            n2++;
            t2 = t2->next;
        }

        if(n1<n2){
            return collisionPoint(headA, headB, n2-n1);
        }else{
            return collisionPoint(headB, headA, n1-n2);
        }

        return NULL;
    }
};

"Time Complexity:O(m+n), where 'm' and 'n' are the lengths of the linked lists, due to traversing both lists to find their lengths and then traversing again to find the collision point.
Space Complexity:O(1), because the algorithm uses a constant amount of extra space regardless of the input size."


// Brute Force
// Using MAP

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp = headA;
        unordered_map<ListNode*, int> mpp;
        while(temp!=NULL){
            mpp[temp] = 1;
            temp = temp->next;
        }

        temp = headB;
        while(temp!=NULL){
            if(mpp.find(temp) != mpp.end()){
                return temp;
            }
            temp = temp->next;
        }

        return NULL;
    }
};

"TC = O(n+m)
SC = O(n)"