class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        Node* temp1=head;
        vector<pair<int,int>>ans;
        while(temp1){
            Node* temp2=temp1->next;
            while(temp2){
                if(temp1->data+temp2->data==target){
                 ans.push_back({temp1->data,temp2->data});
                }
                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
        return ans;
    }
};
//TC=>O(N)  SC=>O(1)


class Solution
{
public:
    Node* findTail(Node* head){
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        return temp;
    }


    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
      Node* right=findTail(head);
      Node* left=head;
      vector<pair<int,int>>ans;
      if(head==NULL){
          return {};
      } //return empty pair
      while(left->data<right->data){  // why not working //left!=right
          if(left->data+right->data<target){
              left=left->next;
          }
          if(left->data+right->data>target){
              right=right->prev;
          }
          if(left->data+right->data==target){
              ans.push_back({left->data,right->data});
              left=left->next;
              right=right->prev;
          }
      }
        return ans;
    }
};
//TC=>O(2N) Distinct element no duplicate elements
