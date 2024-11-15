#include <iostream>

using namespace std;

int main()
{   if(head==NULL||head->next==NULL)return NULL;
    Node* temp=head; //for deleting
    head=head->next; //changing the head to the next element
    head->prev=NULL;
    delete temp;
    return head;
}
