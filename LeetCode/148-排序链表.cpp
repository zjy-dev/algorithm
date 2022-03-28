#include"LeetCode.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        auto ans = new ListNode(0, head);

        auto sorted = head;
        
        // soered->next 非空则说明还未排序完
        while (sorted != NULL && sorted->next != NULL) {
            // 下一个要插入排序的元素p
            auto p = sorted->next;

            // 已经递增就别插入了
            if (p->val >= sorted->val) { 
                sorted = sorted->next;
                continue;
            }
            
            // 找到要插入的位置
            auto t = ans;
            while (t->next->val < p->val) {
                t = t->next;
            }

            // 从原链表删除p
            sorted->next = sorted->next->next;

            // 将p插入
            p->next = t->next, t->next = p;
        }

        return ans->next;
    }
};