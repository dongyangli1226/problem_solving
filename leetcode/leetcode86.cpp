//Partition List (LinkedList)
//all node less than x will on the left side and all node greater or equal to x will on right side

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* smallHead = new ListNode(0);
    ListNode* bigHead = new ListNode(0);
    ListNode* small = smallHead;
    ListNode* big = bigHead;

    while(head != NULL){
        ListNode* temp = new ListNode(head->val);
        if(temp->val < x){
            small->next = temp;
            small = small->next;
        }
        else{
            big->next = temp;
            big = big->next;
        }

        head = head->next;
    }

    small->next = bigHead->next;

    return smallHead->next;
}