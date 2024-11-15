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
ListNode* reverse(ListNode* head){
    ListNode* temp=head;
    ListNode* prev=NULL;
    while(temp!=NULL){
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *newHead=reverse(slow);
        ListNode* first=head,*second= newHead;
        while(first!=NULL&&second!=NULL){
            if(first->val!=second->val) return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }
};

/*
While solving by stack we used extra space

So to reduce space complexity

We can find palindrome or not by comparing from the first element to
the middle as well as from the last element to the middle.
(Compare first half with second half

If any of the element is not equal then not palindrome

But we cannot traverse the second half(from last to the middle)

 so we have to reverse the second half.

 Given
 1->2->3->2->1->X (In case of odd points the first middle element)
       s     f

 1->2->3->3->2->1->X  (In case of even points the second middle element)
          s        f
Find middle element by tortoise and hare method

reverse the second half and find its newHead

1->2->3-------|     (Compare till the element remains in one of the half
          1->2->X

1->2->3--------|
         1->2->3->X



*/
