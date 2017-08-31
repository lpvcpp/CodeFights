// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {

    auto la = a; auto lb =b;
    vector<int> vA , vB, vR;
    while(la != nullptr)
    {
        vA.push_back(la->value);
        la = la->next;
    }
     while(lb != nullptr)
    {
        vB.push_back(lb->value);
        lb = lb->next;
    }   

    int vaLength = vA.size(), vbLength  = vB.size();
    
    int rmd =0, temp;
    for(int i = vaLength-1,  j = vbLength-1; i >=0 || j >=0; i--,j--)
    {
        temp = 0;
        if(i >=0 ) temp += vA[i];
        if(j >=0) temp += vB[j];
        temp += rmd; rmd = 0;
        if(temp > 9999) 
        {rmd = 1; temp -= 10000;
        }
        
        vR.push_back(temp);
    }    
    
    if(rmd == 1) vR.push_back(1);
    ListNode<int> *head, *result, *listTemp;
    int l = vR.size();
    cout << l << endl;
    result = new ListNode(0);
    result->value = vR[l-1];
    result->next = nullptr;
    
    head = result;
    
    for(int i = l-2; i >=0; i--)
    {
        listTemp = new ListNode(0);
        listTemp->value = vR[i];
        listTemp->next = nullptr;
        result->next = listTemp;
        result = listTemp;
    }
    
      
    return head;
}

