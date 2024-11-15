
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        Node* temp=head;
        //Initialize a Linked list
        while(temp){
            Node* next=temp->next;
            Node* newNode=new Node(temp->val);
            temp->next=newNode;
            temp->next->next=next;
            temp=next;
        }

        //Setting random pointers of new Nodes
        temp=head;
        while(temp){
            Node* rand=temp->random;
            if(temp->random){ //sometimes temp->random may be null and null->next is invalid
                temp->next->random=rand->next;
            }
            temp=temp->next->next;
        }

        //Separating both the linked list
        Node* orig=head;
        Node* copy=head->next;
        Node* copyHead=copy;
        while(orig){
            orig->next=orig->next->next;
            if(copy->next){ //if copy->next(orig) exist then original also exist
            copy->next=copy->next->next;
            }
            orig=orig->next;
            copy=copy->next;
        }
        return copyHead;
    }
};



/*
Clone a linked list with next and random pointer
1->2->3->4->5->X

1 temp  save next=2

new node(temp->data(1))

1->next had 2 before but overrided with 1
1->next=new Node

1   2(next)
 \ /
  1 temp->next->next=next

  o
  1   2   3   4   X
   \ / \ / \ / \ /
    1   2   3   4
    c


*/
