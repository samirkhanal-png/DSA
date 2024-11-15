class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
     Node* temp=head;
     int cnt0=0,cnt1=0,cnt2=0;
     while(temp){
         if(temp->data==0){
             cnt0++;
         }
         else if(temp->data==1){
             cnt1++;
         }
         else if(temp->data==2){
             cnt2++;
         }
         temp=temp->next;
     }

     temp=head;
     while(temp){
         if(cnt0){
             temp->data=0;
             cnt0--;
         }
         else if(cnt1){
             temp->data=1;
             cnt1--;
         }
         else if(cnt2){
             temp->data=2;
             cnt2--;
         }
         temp=temp->next;
     }
     return head;
    }
};
//TC->O(2n) two pass Solution

//SC->O(1)


class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
    Node *zeroHead=new Node(-1),*oneHead=new Node(-1),*twoHead=new Node(-1);
    Node *zero=zeroHead,*one=oneHead,*two=twoHead;
    Node *temp=head;
    while(temp){
        if(temp->data==0){
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1){
            one->next=temp;
            one=one->next;
        }
        else if(temp->data==2){
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    //Connecting all these linked list
    //
    zero->next=(oneHead->next)?oneHead->next:twoHead->next;
    one->next=twoHead->next;
    two->next=NULL;

    Node *newHead=zeroHead->next;
    return newHead;
    }
};
/*
TC:O(n)
SC:O(1)

0->1->1->2->2->2->2->2->X

zero=new Node(-1) is for initializing a linked list

zero-1->0->X zero pointer is currently here
one -1->1->1->X one pointer here
two -1->2->2->2->2->2->X two's pointer here

zero->next=oneHead->next  -1->1 points here if 1 exists

else points to 2

one->next=twohead->next

we are going to return zerohead->next so everything should be connected to it

there is no problem if zero exists and anything does not exist after that

if zero does not exist then also we have -1 connect it to oneHead->next
onehead->next does not exist then we connect it to twoHead->next;

if all of them are present then connecting each of them one by one

*/

