/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head){
        ListNode* temp=head;
        int len=0;
        while(temp){
          len++;
          temp=temp->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int len1=getLength(temp1);
        int len2=getLength(temp2);

        while(len1>len2){
            len1--;
            temp1=temp1->next;
        } //When len1 becomes equal to len2 then it comes out of the loop.


        while(len2>len1){
            len2--;
            temp2=temp2->next;
        } //When len2 becomes equal to len1 then it comes out of the loop.

        //At this point head of both are standing at the same point.

        while(temp1!=temp2){
          temp1=temp1->next;
          temp2=temp2->next;
        }
        return temp1;
    }
};

/*
Optimal Approach:
    Length
TC:O(N1+N2)+O(n2-n1)+O(N1)

SC:O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:


    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     if(headA==NULL||headB==NULL)return NULL;
     ListNode* t1=headA,*t2=headB;
     while(t1!=t2){ //enter the loop only when t1!=t2 at the first head
        t1=t1->next;
        t2=t2->next;

        if(t1==t2)return t1; //First of all we should check if equal or not also we need to check if both are at the end of linked list if not checked here then it may go to the next one
        if(t1==NULL)t1=headB;
        if(t2==NULL)t2=headA;
     }
     return t1; //when t1==t2 at first head only then returns t1
}
};
/*

The goal is to align the end of both lists to detect the intersection point.
By switching pointers when one reaches the end, you compensate for
the difference in length. The shorter list will start from the head
 of the longer list, and vice versa. This "switching" makes sure the
 longer list's pointer moves extra steps until both pointers are
 aligned.
TC:O(n1+n2)

      3->1
           \   t2     t1
            4->6->2->X
--d--     /     --d--
1->2->4->5

Here, t2 is d steps behind t1

Here both heads are aligned if something points to the first head of upper linked list

and something points to the third node of the lower linked list simultaneously

Since t1 is moving by d dist ahead and t2 is d dist below

Exchanging their routes they point to the same starting point




*/
