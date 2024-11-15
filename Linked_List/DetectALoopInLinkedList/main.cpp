class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        map<ListNode*,int> mpp; //using a map to store the entire node with its address(not the value) and if it has previously occured in the map
        while(temp){
            if(mpp[temp]) return true;
            mpp[temp]=1; //element already lies in the cycle
            temp=temp->next;
        }
        return false;
    }
};
//TC=>O(n)   SC=>O(n)  reduce space complexity

//If there exists a min of 1 node where we start and reach back.

class Solution {
public:
    bool hasCycle(ListNode *head) {
     ListNode* slow=head;
     ListNode* fast=head;
     while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
     }
     return false;
    }
};

/*
If the linked list is straight then slow and fast would never be at the same point and at last would come at the end of the linked list

If slow and fast pointer ever stand at the same point that means there exists a loop
  slow     4
1->2->3        5 fast
               6
        9  8  7

Difference between fast and slow is 5

It would go on decreasing by one in every steps and finally come to zero.

Slow is moving by one and fast is moving by two

No matter how far slow is from fast d reaches to zero ultimately.(that is it will collide) finally

*/
