#include"LeetCode.h"

struct Node {
    Node *pre, *next;

    // 记录key是为了删除的时候方便
    int key, val;
};

class LRUCache {
public:
    int cap, cnt;
    unordered_map<int, Node*> hash;
    Node *head, *tail;

    LRUCache(int capacity) {
        this->cap = capacity;
        this->cnt = 0;
        this->head = new Node({NULL, NULL, 0, 0});
        this->tail = new Node({NULL, NULL, 0, 0});
        this->head->next = tail, this->tail->pre = head;
    }
    
    int get(int key) {
        // 不存在, 就返回-1
        if (hash.count(key) == 0) {
            return -1;
        }

        // 存在, 则更新其位置到表头
        auto t = hash[key];

        // 从当前位置删除
        t->pre->next = t->next, t->next->pre = t->pre;

        // 头插
        t->next = head->next, t->pre = head;
        head->next = t;
        t->next->pre = t;

        return t->val;
    }
    
    void put(int key, int value) {
        // 若存在, 则更新其位置
        if (hash.count(key) == 1) {
            auto t = hash[key];

            // 从当前位置删除
            t->pre->next = t->next, t->next->pre = t->pre;

            // 头插
            t->next = head->next, t->pre = head;
            head->next = t;
            t->next->pre = t;

            // 更新其值
            t->val = value;

        } else { // 不存在

            // 如果满了, 就要删除最不活跃的表尾元素
            if (this->cnt == cap) {
                // 体现出记录key的好处
                hash.erase(tail->pre->key);
                tail->pre = tail->pre->pre, tail->pre->next = tail;
            } else {
                this->cnt++;
            }
            

            // 头插
            auto t = new Node({NULL, NULL, key, value});
            t->next = head->next, t->pre = head;
            head->next = t;
            t->next->pre = t;

            // 加入到哈希表
            hash[key] = t;
        }
    }
};

