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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        ListNode* dummyNode=new ListNode(-1);
        ListNode* sumNode=dummyNode;

        while(temp1!=NULL||temp2!=NULL){
            int sum=carry;

            if(temp1){
             sum+=temp1->val;
             temp1=temp1->next;
            }

            if(temp2){
                sum+=temp2->val;
                temp2=temp2->next;
            }
            carry=sum/10;
            sumNode->next=new ListNode(sum%10);//-1->7(sum)
            sumNode=sumNode->next;//(pointing to 7)
        }

      // After the loop, add the carry if it exists
        if (carry) {
            sumNode->next = new ListNode(carry);
        }


        return dummyNode->next;
    }
};

/*
Actually the numbers are 342 and 465 but since the addition is performed from backwards
 2  4  3
 5  6  4

 7  0  8(7+1)
*/
