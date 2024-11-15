#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}


//Function removeTail
/*
1->8->9->3->X
      ^

Store head in temporary node to preserve the head

and traverse through the linked list (temp=temp->next)

Stop at the second last element

temp->next->next==null

temp currently points to 9
free(temp->next) 9->next

temp->next=null (9->next=null)

*/
Node* removeTail(Node* head) {
  Node* temp=head;
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  free(temp->next);
  temp->next=NULL;
  return head;
}

int main() {
    // Creating nodes
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Printing the original list
    cout << "Original Linked List: ";
    printList(head);

    // Call to removeTail function (currently does nothing)
    head = removeTail(head);

    // Printing the list after trying to remove the tail
    cout << "Linked List after removing tail: ";
    printList(head);

    return 0;
}
