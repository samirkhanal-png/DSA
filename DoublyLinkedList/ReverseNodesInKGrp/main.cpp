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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL&&cnt<k){ //at last for example k=2  3->X cnt=1<2 but temp==NULL comes out
            cnt++;
            temp=temp->next;
        }

        if(cnt<k)return head; //Base case

        //Reverse
        ListNode* prev=NULL;
        temp=head;
        ListNode* next=NULL;
        cnt=0;
        while(temp!=NULL&&cnt<k){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
            cnt++;
        }

        if(next!=NULL){ //if there is next element then there is next group
            head->next=reverseKGroup(next,k);
        }

        return prev; //returning the prev of the first called function first k group after reversed

    }
};
/*
TC:O(n) O(2n) n for counting and n for reversing

SC:auxiliary space O(N)
h    h    h    h     //in next
1->2|3->4|5->6|7->X
   h->next
2->1 4->3 6->5 7->X
p    p     p     return head
ret

*/


