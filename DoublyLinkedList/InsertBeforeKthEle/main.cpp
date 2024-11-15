#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    Node(int val, Node* p, Node* n) : data(val), prev(p), next(n) {}
};

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


Node* insertAtFront(Node *head, int k) {
   Node* newHead=new Node(k,nullptr,head);
   return newHead;
}

Node* insertBeforeKth(Node* head,int k,int val)
{ Node* temp=head;
  int cnt=0;

  if(k==1)return insertAtFront(head,val);

  while(temp){
    cnt++;
    if(cnt==k)break;
    temp=temp->next;
  }
  Node* front=temp->prev;//2
  Node* back=temp;//3
  Node* newNode=new Node(10,front,temp);
  front->next=newNode;
  back->prev=newNode;

  return head;
}

int main() {
    // Create a doubly linked list: 2 <-> 3 <-> 4 <-> 1
    Node* head = new Node(2);
    Node* second = new Node(3);
    Node* third = new Node(4);
    Node* fourth = new Node(1);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    cout << "Original List: ";
    printList(head);

    int k = 2;
    int val = 10;

    // Insert before k-th element
    head = insertBeforeKth(head, k, val);

    cout << "Updated List: ";
    printList(head);

    // Free memory
    Node* temp = head;
    while (temp) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}


/*
2->3->4->1->X  val=10

2->10->3->4->1->X
back  temp

k=1 insertBeforeHead

k=n insertBeforeTail

When kth element is neither the head nor the tail.

k=2


*/
