#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    //
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}


Node* insertAtHead(Node* head, int value) {
    head=new Node(value,head);
    //assigning new node to by linking it to the head and
    return head;
}

int main() {
    Node* head = new Node(20);
    head->next = new Node(30);
    head->next->next = new Node(40);

    cout << "Original Linked List: ";
    printList(head);

    int value = 10;
    head = insertAtHead(head, value);

    cout << "Linked List after inserting value " << value << " at the head: ";
    printList(head);

    return 0;
}
