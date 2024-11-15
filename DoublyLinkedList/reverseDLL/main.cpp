#include <iostream>

using namespace std;

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
     if (head == NULL || head->next == NULL)
        return head;
     DLLNode* temp=head;
     DLLNode* back=NULL;
     while(temp){
         DLLNode* front=temp->next;
         temp->next=back; //changing the links
         back=temp; //pay attention it should be after temp->next
                    //as it stores the previous node
         temp->prev=temp->next;
         temp=front;
     }
     return back;
    }
};
/*
   4-><-2-><-3-><-1-><-X

   X<-4<- ->2<- ->3<- ->1<- ->X

   We are reversing the link while traversing only.

   Just like reversing a singly linked list but here on both ways
   Before this, back=3
   When temp reaches 1->X temp->next=back(3)
                     back=1
                     temp->prev=temp->next(NULL)
   loop comes out

   return back

*/
