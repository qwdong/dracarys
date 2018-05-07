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

int main (int argc, char** argv)
{

    ListNode *foo(new ListNode(0));
    ListNode *list(foo);
    ListNode *head(foo);

    for(int i = 0; i < 5; i++)
    {
        list->next = new ListNode(i);
        list = list->next;
    }
    head = head->next;
    delete foo;

    ListNode* mid = getMid(head);
    while(mid)
    {
        std::cout << mid->val << " ";
        mid = mid->next;
    }
    std::cout << std::endl;


    return (0);
}
