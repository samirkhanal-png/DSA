//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node* head) {
    if (head == NULL) cout << -1;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
// User function Template for C++


/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp=*head_ref;
        Node* nodeToDelete;
        while(temp){
            if(temp->data==x){
                if(temp==*head_ref){ //
                    *head_ref=temp->next;
                }
                Node* nextNode=temp->next;
                Node* prevNode=temp->prev;

                if(nextNode)nextNode->prev=prevNode;                    //checking for last node lastNode->X X is nextNode
                if(prevNode)prevNode->next=nextNode;                    //checking for first node
                    // Delete the current node and move temp to nextNode
                nodeToDelete = temp;
                temp = nextNode;
                delete nodeToDelete;
            }
                // Move to the next node if no deletion
                temp = temp->next;
        }
    }
};
