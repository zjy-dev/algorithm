#include"LeetCode.h"

class Solution{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* p = NULL;
        while(head)
        {
            auto ne = head->next;
            head->next = p;
            p = head, head = ne;
        }

        return p;
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;
    obj.reverseList();
    return 0;
}
