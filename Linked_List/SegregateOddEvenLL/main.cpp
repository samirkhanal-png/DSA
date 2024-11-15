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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode *temp=head;
        ListNode *odd=head;
        ListNode *even=head->next;
        vector<int>arr;

        while(odd&&odd->next){
        arr.push_back(odd->val);
        odd=odd->next->next;
        }
        if(odd)arr.push_back(odd->val);

        while(even&&even->next){
            arr.push_back(even->val);
            even=even->next->next;
        }
        if(even)arr.push_back(even->val);

         int i=0;
        while(temp){
            temp->val=arr[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};

/*
   e     e     e     e
1->3->4->2->5->6->X  Segmentation fault

Out of bound memory

So if the temp->next is equal to null then after two points it points to the invalid memory location
giving segmentation fault

o     o     o     o
1->3->4->2->5->6->X

o     o     o     o
1->3->4->2->5->X->X invalid

*/


