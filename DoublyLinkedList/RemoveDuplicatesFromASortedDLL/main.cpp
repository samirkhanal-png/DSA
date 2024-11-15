//my own logic but it is not working
class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {if(head==NULL)return NULL;
     Node* temp=head;
     Node* prevNode=NULL;
     while(temp->next){
        if(prevNode||prevNode->data==temp->data){//equal to previous one so lets delete it
            Node* NodeToDelete=temp;
            temp=temp->next;
            delete NodeToDelete;
            continue;
        }
        //When not equal then control comes here and here temp is the next node
        temp->prev=prevNode;
        if(prevNode)prevNode->next=temp;
        prevNode=temp;
        temp=temp->next;
     }
     return head;
    }
};

/*
Note:Since it is a sorted doubly linked list, duplicates are
always consecutive.

nextNode is the only first element that is not equivalent to current
Node.

Beyond the last element there can be no duplicates

All test cases are not running

*/


class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {Node* temp=head;
     while(temp && temp->next){ //temp points to the previousNode and nexNode to the next
         Node* nextNode=temp->next;//to check for the nextNode
         while(nextNode->data==temp->data&&nextNode){
             Node* duplicate=nextNode;
             nextNode=nextNode->next;
             delete duplicate;
         }
         //When not equal comes out of loop and points to the distinct element
         temp->next=nextNode;
         if(nextNode)nextNode->prev=temp;
         temp=temp->next;
     }
     return head;
    }
};
