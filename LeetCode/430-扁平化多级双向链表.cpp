#include"LeetCode.h"

class Solution{
public:
    Node* flatten(Node* head) 
    {
        flattenGetTail(head);
        return head;
    }

    Node* flattenGetTail(Node* head)
    {
        if(!head)
            return NULL;

        auto p = head, ans = p->prev;

        while(p)
        {
            ans = p;
            if(p->child)
            {
                auto childTail = flattenGetTail(p->child);

                p->child->prev = p;
                childTail->next = p->next;

                if(p->next)
                    p->next->prev = childTail;
                p->next = p->child;

                p->child = NULL;
                p = childTail;
            }
            else
                p = p->next;
        }

        return ans;
    }
};