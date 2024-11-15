/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/
Node* insertAtFront(Node *head, int k) {
   Node* newHead=new Node(k,nullptr,head);
   return newHead;
}


Node * insertAtTail(Node *head, int k) {
  //If head is itself empty
  if (head == nullptr) {
        return new Node(k);
    }

  //When there is only one element it is the head so insert before it
  //which is similar to insertBefore Head
  if(head->next==NULL){
    return insertAtFront(head,k);
  }

  Node* temp=head;
  Node* back=NULL;
  while(temp->next!=NULL){
      back=temp;
      temp=temp->next;
  }
  Node* newNode=new Node(k,back,temp);
  back->next=newNode;
  temp->prev=newNode;
  return head;
}
