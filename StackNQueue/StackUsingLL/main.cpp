class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        StackNode* temp=new StackNode(x);
        temp->next=top; //previous top
        top=temp; //new top

    }

    int pop() {
        if(top==NULL)return -1;
        StackNode* temp=top;
        top=top->next;
        return temp->data;
    }

    MyStack() { top = NULL; }
};

/*
push(4,2,3,1)

 top(NULL)<-4(top)

 temp 2

 NULL<4<2(top)

 NULL<4<2<3(top)

 NULL<4<2<3<1(top)

 Size of linked list is not fixed it can be increased and decreased at any time

 So no need to check if  it is full

 Empty when there is null
*/
