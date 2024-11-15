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

//Write yourself
Node* removeHead(Node* head) {
    Node* temp=head;head=head->next;   //changing the head
    free(temp);        //deleting the memory allocated to the current head
    return head;}

int main() {
    // Creating nodes
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Printing the original list
    cout << "Original Linked List: ";
    printList(head);

    // Call to removeHead function (currently does nothing)
    head = removeHead(head);

    // Printing the list after trying to remove head
    cout << "Linked List after removing head: ";
    printList(head);

    return 0;
}

