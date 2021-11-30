#include"LeetCode.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        if(!head)
            return NULL;
        
        auto ans = new ListNode(0, head);
        auto tail = head, p = head->next;//进入循环时p始终在tail后面一个
        while(p)
        {
            if(tail->val <= p->val)
                tail = p;
            else
            {
                auto pre = ans;
                while(pre->next->val < p->val)
                    pre = pre->next;
                
                //下一个未排好的就是p->next
                tail->next = p->next;

                p->next = pre->next;
                pre->next = p;
            }

            p = tail->next;
        }
        return ans->next;
    }
};