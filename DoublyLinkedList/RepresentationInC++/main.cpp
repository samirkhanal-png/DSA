#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1,Node* next1,Node* back1){
      data=data1;
      next=next1;
      back=back1;
    }

    Node(int data2){
      data=data2;
      next=nullptr;
      back=nullptr;
    }

};

//Doubly linked list can be traversed forward and backward
