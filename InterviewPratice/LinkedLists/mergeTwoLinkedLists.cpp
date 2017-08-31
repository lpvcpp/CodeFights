// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {
    
//   ListNode<int> * result = nullptr;
//   if( l1 == nullptr)
//     return l2;
//   else if(l2 == nullptr)
//     return l1;
  
//   if(l1->value <= l2->value)
//   {
//     result = l1;
//     result->next = mergeTwoLinkedLists(l1->next, l2);
//   }
//   else{
//     result = l2;
//     result->next = mergeTwoLinkedLists(l1, l2->next);
//   }
//   return result;

    ListNode<int> result (0);
    ListNode<int> *p = &result;
    
    while( l1 || l2)
    {
        if( !l1 || l2 && l1->value > l2->value)
        {
            p = p->next = l2;
            l2 = l2 ->next;
        }
        else {
            p= p ->next = l1;
            l1 = l1->next;
        }
    }
    return result.next;
    
}

