Node *deleteTail(Node* head){

    if(head == nullptr || head->next == nullptr) return nullptr;

    Node *temp = head;

    while(temp->next != NULL){

        temp = temp->next;

    }

    Node *back = temp->prev;

    back->next = nullptr;

    temp->prev = nullptr;

    delete temp;

    return head;

}
