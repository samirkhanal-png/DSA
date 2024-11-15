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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; //no need to rotate

        ListNode* temp = head;
        int len = 1;
        while (temp->next) {
            temp = temp->next;
            len++;
        }

        temp->next = head;//circular linked list

        k = k % len;
        if (k == 0) { //if after normalizing 0 rotation is found
            temp->next = nullptr;
            return head;
        }

        int reachNewTail = len - k -1;
        temp = head;
        while(reachNewTail--){
            temp = temp->next;
        }
         //temp is the newTail
        ListNode* newHead = temp->next; //next of tail is newHead
        temp->next = nullptr;

        return newHead;
    }
};

/*
   1->2->3->4->5->X'

   k=0 or a single element linked list return head

   4->5->1->2->3->X

   old tail joins old head forming a circular linked list

   k=2   newTailDist=len-k-1=2 jumps of temp->next

   k=10 10%5=0 no rotation break the tail

*/
