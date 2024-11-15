/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *//
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int cnt=0;
        while(temp){
         cnt++;
         temp=temp->next;
        }
        int mid=(cnt/2)+1; //For odd 5 5/2->2+1=3   //For even 6 6/2->3+1=4

        temp=head; //again iterating in the linked list from beginning
        while(temp){
            mid--; //already accessed one element that is head so decreasing before only
            if(mid==0)return temp;
            temp=temp->next;
        }
        return temp;
    }
};

//Optimized Solution-> O(N/2)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
     ListNode* slow=head;
     ListNode* fast=head;
     while(fast!=NULL&&fast->next!=NULL){ //For odd => fast->next For even=> fast
        slow=slow->next;
        fast=fast->next->next;
     }
     return slow;
    }
};
/*
Fast pointer is moving at x speed and slow pointer is moving at x/2 speed so the slow pointer is at the middle when fast reaches the end.

Maybe this method can be used for one third, one fourth and so on.

Dry run:
       fast   fast  fast   fast
For odd: 1->2->3->4->5->6->x
       slow sl sl sl

         sl  sl sl
For even: 1->2->3->4->5->X
         fs     fs    fs(stops)



*/


