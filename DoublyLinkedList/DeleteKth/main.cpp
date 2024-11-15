#include <iostream>

using namespace std;

Node *deleteNode(Node *head, int k){
 Node *temp=head;
 int cnt=0;

 while(temp){
   cnt++;
   if(cnt==k)break;
   temp=temp->next;
 }
 Node* back=temp->prev;
 Node* front=temp->next;

 if(back==NULL&&front==NULL){
     delete temp;
     return NULL;
 }
 else if(back==NULL){
   delete temp;
   return head->next;
 }
 else if(front==NULL){
   delete temp;
   back->next=NULL;
   return head;
 }
 else{
   delete temp;
   back->next=front;
   front->prev=back;
 }

 return head;

}

/*
When we reach the kth element break
   |-----|
1->2->3->4->5->6->7->8->X
      temp               break

Remove k=3rd element from the linked list

prev=temp->back
next=temp->next

prev->next=next;

If there is only one element in the linked list then delete the head

prev=NULL and front=NULL

delete temp;
return null

if k=1 and there are more than one element then
1->2->3->4->5->6->7->8->X
                     temp
if prev=NULL
delete temp

if temp is at the last element delete the tail

*/
