#include <iostream>

using namespace std;

/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node* insertAtFront(Node *head, int k) {
   Node* newHead=new Node(k,nullptr,head);
   return newHead;
}
/*
2->3->4->10->X   val=10

10->2->3->4->X
Node *newHead=new Node(val,head,nullptr)

next is pointing to the had and back is pointing to null

*/
