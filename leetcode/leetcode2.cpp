#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* head = new ListNode(0);
    ListNode* current;
    current = head;

    int sum=0;
    int rem=0;
    while(l1||l2){
        if(l1 != NULL && l2 != NULL){
            sum = l1->val + l2->val;
        }
        else if(l1 == NULL){
            sum = l2->val;
        }
        else{
            sum = l1->val;
        }
        current->next = new ListNode(0);
        current = current->next;

        if(sum >= 10){
            int digit = sum - 10;
            if(rem == 1){
                current->val = digit+1;
            }
            else{
                current->val = digit;
            }
            rem = 1;
        }
        else{
            if(rem == 1){
                current->val = sum + 1;
                if(current->val >= 10){
                    current->val = current->val - 10;
                    rem = 1;
                }else{
                    rem = 0;
                }
            }
            else{
                current->val = sum;
            }
        }
        if(l1 != NULL) l1 = l1->next;
        if(l2 != NULL) l2 = l2->next;
    }

    if(rem == 1){
        current -> next = new ListNode(1);
    }

    return head->next;
}

int main(){
    cout << "testing....." << endl;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);

    ListNode* l2 = new ListNode(4);
    l2->next = new ListNode(5);

    ListNode* h = addTwoNumbers(l1, l2);

    cout << "Output: " << endl;
    while(h){
        cout << h->val;
        h=h->next;
    }
    cout << endl;
}