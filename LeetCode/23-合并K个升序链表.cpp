#include"LeetCode.h"

struct Node{
    ListNode* p;
    bool operator<(const Node& obj)const{
        return p->val > obj.p->val;
    }
};

class Solution {
public:
    priority_queue<Node> heap;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto p = new ListNode();
        auto ans = p;

        for(auto list : lists)
            if(list)
                heap.push({list});
        
        while(heap.size()){
            auto t = heap.top().p;
            heap.pop();
            
            p->next = t;
            p = p->next;
            if(t->next)
                heap.push({t->next});
        }

        return ans->next;
    }

};