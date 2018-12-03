/* geeksforgeeks

Example:
Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
Output:  3->2->1->6->5->4->8->7->NULL. 

*/
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

Node* reverseByK(Node* head, int k){
    int count = 0;
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(current != NULL && count < k){
        next = current->next;
        current->next = prev;
        prev = current;

        current = next;
        count++;
    }

    if(next != NULL){
        head->next = reverseByK(next, k);
    }

    return prev;
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

    Node* head = reverseByK(head1, 3); 
    std::cout << "\nReversed linked list\n"; 
    while(head != NULL){
        std::cout << head->data << "->";
        head = head->next;
    }
    std::cout << std::endl;
    return 0; 
} 