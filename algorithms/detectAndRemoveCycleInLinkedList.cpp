//geeksforgeeks
//hashing addresses of linked list nodes

#include <iostream>
#include <unordered_map>

struct Node 
{ 
    int key; 
    struct Node *next; 
}; 
  
Node *newNode(int key) 
{ 
    Node *temp = new Node; 
    temp->key = key; 
    temp->next = NULL; 
    return temp; 
}

Node* detectCycleAndRemove(Node* head){
    std::unordered_map<Node*, int> node_map;
    Node* res = head;
    Node* last = NULL;

    while(head!=NULL){
        if(!node_map[head]){
            node_map[head]++;
            last = head;
            head = head->next;
        }
        else{
            last->next = NULL;
            break;
        }
    }

    return res;
}

int main() 
{ 
    Node *head = newNode(50); 
    head->next = head; 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10); 
  
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next; 
  
    //printList(head); 
    //Node*h = head;
    Node*h = detectCycleAndRemove(head); 
  
    printf("Linked List after removing loop \n");
    while(h!=NULL){
        std::cout << h->key << "->";
        h = h->next;
    }
    std::cout << std::endl;
    
  
    return 0; 
} 