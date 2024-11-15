class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev; //last previous element is the new head
    }
};
/*
Time Complexity:O(n)
1->2->3->4->5->X

prev=null(at the beginning)


If we do so we are not able to traverse to the next one so saving it in a variable front for traversing as well as linking
front=temp->next

1->X temp->next=prev

saving the current temp=1 in prev for linking to the next element 2
prev=temp

temp=front(temp->next) for traversing to the next
*/

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
 //Better solution: O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) { //Note:head->next is now the head
    if(head==NULL||head->next==NULL)return head;
    ListNode* newHead=reverseList(head->next); //kaam sab return huda garne
    ListNode* front=head->next;
    front->next=head;
    head->next=NULL;

    //reverse garne kaam garepaxi newHead return garne at each level
    return newHead;
    }
};
/*
TC:O(2^n)
h  front
1->/3->2->5   reversed till the point of / in the previous recursion only also 5->2->3->X
|
h   f
3->/2->5
|
h  f
2->/5
|
5   return 5 through each level as it is the newHead after doing the work of reversing in each level

   X<-5 already pointing to null

   TC:O(2^n)

*/
