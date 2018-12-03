//reverse a LinkedList
//assume the LinkedList will never be null
//geeksforgeeks

#include <iostream>

struct Node{
    int data;
    Node* next;
};

Node *newNode(int key) 
{ 
    Node *temp = new Node; 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 

//iterative method
void reverseLinkedList(Node** head){
    Node* current = *head;
    Node* prevNode=NULL;
    Node* nextNode=NULL;

    while(current != NULL){
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        
        current = nextNode;
    }

    *head = prevNode;
}

//recursive (derived from above method)

void reverse(Node* current, Node* prev, Node** head){
    if(current->next == NULL){
        *head = current;
        current->next = prev;
        return;
    }

    Node* next = current->next;
    current->next = prev;

    reverse(next, current, head);
}

void reverse(Node** head){
    reverse(*head, NULL, head);
}

int main() 
{ 
    Node *head1 = newNode(1); 
    head1->next = newNode(2); 
    head1->next->next = newNode(3); 
    head1->next->next->next = newNode(4); 
    head1->next->next->next->next = newNode(5); 
    head1->next->next->next->next->next = newNode(6); 
    head1->next->next->next->next->next->next = newNode(7); 
    head1->next->next->next->next->next->next->next = newNode(8); 

    //reverse(&head1);
    reverseLinkedList(&head1); 
    std::cout << "\nReversed linked list\n"; 
    while(head1 != NULL){
        std::cout << head1->data << "->";
        head1 = head1->next;
    }
    std::cout << std::endl;
    return 0; 
} 