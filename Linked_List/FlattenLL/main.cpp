
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeLL(Node* t1,Node* t2){
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;
        res->next=NULL;
        while(t1&&t2){
            if(t1->data<=t2->data){
                res->bottom=t1;
                t1=t1->bottom;
            }
            else{
                res->bottom=t2;
                t2=t2->bottom;
            }
            res->next=NULL;
            res=res->bottom;
        }

        if(t1){
            res->bottom=t1;
            res->next=NULL;
        }
        else{
            res->bottom=t2;
            res->next=NULL;
        }
        res->bottom->next=NULL;
        return dummyNode->bottom;
    }

    Node *flatten(Node *root) {
      if(root==NULL||root->next==NULL)return root;
      Node* nextEle=flatten(root->next);
      Node* newHead=mergeLL(root,nextEle);
      return newHead;
    }
};

/*
Brute force approach=>push into an array O(n*m) n=horizontal length m=vertical length
                      sort it out X=n*m(no of elements) XlogX
                      convert INTO LL O(n*m)

TC=>2*O(X)+XLogX
SC=>2(X) array space

h  h  h  h  h
3->2->1->4->5->X
   |  |  |  | elements are here
   10
   |
   X
              3     2
f(3)  merge(head,returnedEle)
|             2     1
f(2)  merge(head,returnedEle)
|             1      4
f(1)  merge(head,returnedEle)
|            4       5
f(4)  merge(head,returnedEle)
|
f(5) return 5
|
X

*/
