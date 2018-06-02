#include <iostream>



 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        return NULL;
    }
};

void printList(ListNode *head) {
    while(head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

ListNode* getMid(ListNode* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    ListNode *slow(head);
    ListNode *fast(head->next);

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* mergeLinkedList(ListNode* l1, ListNode* l2)
{

    ListNode  foo(0);
    ListNode *head(&foo);
    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            head->next = l1;
            l1 = l1->next;
        } else {
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }

    head->next = l1 ? l1 : l2;
    return foo.next;
}


// 148. Sort List
ListNode* sortList(ListNode* head) {

        if(NULL == head || head->next == NULL) return head;
        ListNode *mid = getMid(head);

        ListNode *l = sortList(mid->next);
        mid->next = NULL;
        ListNode *r = sortList(head);

        return mergeLinkedList(l, r);
}

// Problem 143 reorder list
void reorderList(ListNode *head) {
        if(NULL == head || NULL == head->next){ return; }
        ListNode foo(0);
        foo.next = head;
        ListNode *fast(head->next), *slow(head);
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode *first(head), *second(slow->next);
        slow->next = NULL;

        ListNode *old_head(second), *new_head(NULL);
        while(second->next) {
            old_head = second->next;
            second->next = new_head;
            new_head = second;
            second = old_head;
        }
        second->next = new_head;
        new_head = second;

        printList(first);
        printList(new_head);

    while(first && new_head) {
        ListNode *tmp = new_head;
        new_head = new_head->next;
        tmp->next = first->next;
        first->next = tmp;
        first = first->next->next;
    }


}

// Problem 328 Odd even linked list
ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode foo(0);
        foo.next = head;
        ListNode *odd(head), *even(head->next);
        ListNode *odd_start(odd), *even_start(even);
        head = head->next->next;

        int cnt(3);

        while(head){
            if(cnt%2 == 0){
                even->next = head;
                head = head->next;
                even = even->next;

            } else {
                odd->next = head;
                head = head->next;
                odd = odd->next;
            }
            cnt++;
        }
        odd->next = even_start;
        even->next = nullptr;
        return foo.next;


    }

ListNode* reverseLinkedList(ListNode *head) {
        if(head == nullptr) return head;

        ListNode *new_head(nullptr);
        while(head) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = new_head;
            new_head = tmp;
        }
        return new_head;
    }
int main (int argc, char** argv)
{

    ListNode *foo(new ListNode(0));
    ListNode *list(foo);
    ListNode *head(foo);

    for(int i = 1; i < 6; i++)
    {
        list->next = new ListNode(i);
        list = list->next;
    }
    head = head->next;

//    ListNode* mid = getMid(head);
//    while(head)
//    {
//        std::cout << head->val << " ";
//        head = head->next;
//    }
//    std::cout << std::endl;

//    std::cout << mid->val << std::endl;

    ListNode *result = reverseLinkedList(head);

    printList(result);

    return (0);
}
