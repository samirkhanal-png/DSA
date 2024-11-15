using namespace std;

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1,Node* next1,Node* back1){
      data=data1;
      next=next1;
      back=back1;
    }

    Node(int data2){
      data=data2;
      next=nullptr;
      back=nullptr;
    }

};

//Doubly linked list can be traversed forward and backward


ArrayToDLL(Node* head)
{   Node* head=new Node(arr[0],NULL,NULL);
    Node* temp=head;
    Node* prev=head;

    for(int i=1;i<n;i++){
        temp->next=arr[i];
        temp=temp->next;
        temp->back=prev;
        prev=temp;
    }

    return head;
}

/*

 for(int i=1;i<n;i++){
   Node* temp=new Node(arr[i],nullptr,prev)
   prev->next=temp;
   prev=temp;
}

*/
