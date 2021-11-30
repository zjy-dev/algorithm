#include"LeetCode.h"

class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        unordered_set<ListNode*> hash;

        while(head)
        {
            if(hash.count(head))
                return true;
            hash.insert(head);
            head = head->next;
        }    
        return false;
    }
};