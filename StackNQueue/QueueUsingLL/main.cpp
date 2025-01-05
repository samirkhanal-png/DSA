//Function to push an element into the queue.
void MyQueue:: push(int x)
{ QueueNode* temp=new QueueNode(x);
  if(front==NULL){
      front=rear=temp;
  }
  else{
      rear->next=temp;
      rear=temp;
  }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{ if(front==NULL)return -1;
  QueueNode* temp=front;
  int value=temp->data;
  front=front->next;
  delete temp;
  return value;
}
/*
push(9)
1->2->3->4
         rear

rear->next=9

1->2->3->4->9
         but rear is still pointing to  4

so making it point to 9

rear=temp

*/
