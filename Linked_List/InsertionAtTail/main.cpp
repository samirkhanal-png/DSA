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

Node* insertAtTail(Node* head, int value) {
    if(head==NULL)return new Node(value);

    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(value);
    temp->next=newNode;
    return head;
}

int main() {
    Node* head = new Node(20);
    head->next = new Node(30);
    head->next->next = new Node(40);

    // Print the original list
    cout << "Original Linked List: ";
    printList(head);

    int value = 50;  // Value to insert at the tail
    head = insertAtTail(head, value);

    // Print the list after inserting at the tail
    cout << "Linked List after inserting value " << value << " at the tail: ";
    printList(head);

    return 0;
}

/*
When we see next is pointing to the null we stop
2->3->1->8->X
         stop
Currently temp points to 8

Make a new node and 8 should point to the new node

temp->next=node;


*/
