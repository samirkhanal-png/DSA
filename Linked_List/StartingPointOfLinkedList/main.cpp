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
    ListNode *detectCycle(ListNode *head) {
        ListNode*temp=head;
        map<ListNode*,int> mpp;
        while(temp){
            if(mpp[temp])return temp;
            mpp[temp]=1;
            temp=temp->next;
        }
        return NULL;
    }
};
