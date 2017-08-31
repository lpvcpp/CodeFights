// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
// https://codefights.com/interview-practice/task/gX7NXPBrYThXZuanm

ListNode<int>* removeKFromList(ListNode<int>* l, int k) {
    ListNode<int> dummy(0);
    dummy.next = l;
    for (ListNode<int>* p = &dummy; p; p = p->next) {
    if (p->next && p->next->value == k) {
            ListNode<int>* removed = p->next;
            p->next = p->next->next;
            delete removed;
        }
    }
    return dummy.next;
}



