//geeksforgeeks

#include <iostream>

struct Node 
{ 
    int data; 
    struct Node* next; 
};

//use fast and slow pointer strategy
void splitListToHalf(Node* source, Node** firstHalf, Node** secondHalf){
    Node* fast;
    Node* slow;

    slow = source;
    fast = source->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    *firstHalf = source;
    *secondHalf = slow->next;
    slow->next = NULL; // split the two lists
}

Node* merge(Node* firstHalf, Node* secondHalf){
    Node* result = NULL;

    if(firstHalf == NULL){
        return secondHalf;
    }
    else if(secondHalf == NULL){
        return firstHalf;
    }

    if(firstHalf->data <= secondHalf->data){
        result = firstHalf;
        result->next = merge(firstHalf->next, secondHalf);
    }
    else{
        result = secondHalf;
        result->next = merge(firstHalf, secondHalf->next);
    }

    return result;
}

void mergeSort(Node** headRef){
    Node* head = *headRef;
    Node* firstHalf;
    Node* secondHalf;

    if(head == NULL || head->next == NULL){
        return;
    }

    splitListToHalf(head, &firstHalf, &secondHalf);

    mergeSort(&firstHalf);
    mergeSort(&secondHalf);

    *headRef = merge(firstHalf, secondHalf);
}