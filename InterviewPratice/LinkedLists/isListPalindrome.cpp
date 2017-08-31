// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
bool isListPalindrome(ListNode<int> * head) {
    
    if(head == nullptr) return true;
    ListNode<int> *p = head;
    ListNode<int> *prev = new ListNode(head->value);
 
    while(p->next != nullptr){
        ListNode<int> *temp = new ListNode(p->next->value);
        temp->next = prev;
        prev = temp;
        p = p->next;
        
    }
 
    ListNode<int> *p1 = head;
    ListNode<int> *p2 = prev;
 
    while(p1!= nullptr){
        if(p1->value != p2->value)
            return false;
 
        p1 = p1->next;
        p2 = p2->next;
    }
 
    return true;
}

