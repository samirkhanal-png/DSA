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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL)return NULL;
        ListNode* temp=head;
        int cnt=0;
        while(temp){
         cnt++;
         temp=temp->next;
        }
        temp=head;
        int midNode=(cnt/2)+1;
        ListNode* prev=NULL;
        while(temp){
         if(midNode==1){
            prev->next=temp->next;
            delete temp;
            break;
         }
         midNode--;
         prev=temp;
         temp=temp->next;
        }
        return head;
    }
};
/*
 TC=>O(n+n/2)

 SC=>O(1)

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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
       if(head==NULL||head->next==NULL)return NULL; //when there is only one item there is no middle item
       ListNode* slow=head;
       ListNode* fast=head;
       ListNode* prev=NULL;
       while(fast!=NULL&&fast->next!=NULL){
        prev=slow; //current one is updated before taking slow to the next one
        slow=slow->next; //points to the middle item
        fast=fast->next->next;
       }
       prev->next=slow->next; //points to the item just after the middle
       delete slow; //deleting the middle item
       return head;
    }
};

/*
 TC:O(N)
 SC:O(1)
*/
