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
/*
Delete the kth element of the linked list
1->8->9->3->X
   |   ^ |
   |_____|

len=4        k=3

      ^
Initialize cnt=0

When cnt==k then connect prev temp(8)->currenttemp->next(3)
standing here

delete the current temp

Note:
Delete the head and tail as we did before

*/
Node* removeKthElement(Node* head, int k) {
    if(head==NULL) return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    Node* temp=head;
    Node
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
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

    int k = 3;  // Position of the element to remove
    head = removeKthElement(head, k);

    // Printing the list after removing the k-th element
    cout << "Linked List after removing element at position " << k << ": ";
    printList(head);

    return 0;
}
