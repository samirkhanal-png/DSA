#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

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
//Insert at the kth position
/*
Insert at the 0th position

Insert at the 1st position

Insert at the kth position
3->1->5->3->X


*/
Node* insertAtK(Node* head, int k, int value) {
    if(head==NULL){
        if(k==1)return newNode(value);
        else return null;
    }

    //Head is not empty and insert at the 1st position similar to insert at head
    if(k==1){
      Node* temp=new Node(value,head);
      return temp;
    }

    int cnt=0;

    return head;
}

int main() {
    Node* head = new Node(20);
    head->next = new Node(30);
    head->next->next = new Node(40);

    cout << "Original Linked List: ";
    printList(head);

    int k = 2;
    int value = 25;
    head = insertAtK(head, k, value);

    cout << "Linked List after inserting value " << value << " at position " << k << ": ";
    printList(head);

    return 0;
}
