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

Node* removeByValue(Node* head, int value) {
    if(head==NULL)return head;

    if(head->data==value){  //When the value is found in the head itself
        Node *temp=head;
        head=head->next;
        free(temp);
    }

    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
     if(temp->data==value){ //When the value is found then apply the process
        prev->next=prev->next->next;
        free(temp);
        break;
     }
     prev=temp;
     temp=temp->next;
    }

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

    int value = 30;  // Value to remove
    head = removeByValue(head, value);

    // Printing the list after removing the node with the given value
    cout << "Linked List after removing value " << value << ": ";
    printList(head);

    return 0;
}
