class Solution {
  public:
    int helper(Node *temp){
        if(temp==NULL)return 1;

        int sum=helper(temp->next)+temp->data;
        temp->data=sum%10;
        return sum/10;

    }

    Node* addOne(Node* head) {
    int carry=helper(head);

    if(carry==1){
        Node * newNode=new Node(1);
        newNode->next=head;
        return newNode;
    }

    return head;

    }
};
