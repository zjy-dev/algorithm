#include"LeetCode.h"

struct MyNode {
    int key, val;
    MyNode* next;
    MyNode* prev;
};

class LRUCache {
public:
    int cap;
    int cnt = 0;
    MyNode* head;
    MyNode* tail;
    unordered_map<int, MyNode*> hash;
    LRUCache(int capacity) {
        this->cap = capacity;
        this->head = new MyNode({0, 0, NULL, NULL});
        this->tail = new MyNode({0, 0, NULL, NULL});
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if (hash.count(key) == 0) {
            return -1;
        }

        // 将最活跃的元素从当前位置删除
        auto t = hash[key];
        t->prev->next = t->next;
        t->next->prev = t->prev;
        
        // 将最活跃的元素添加到表头
        t->next = head->next;
        t->prev = head;
        head->next->prev = t;
        head->next = t;

        return hash[key]->val;
    }
    
    void put(int key, int value) {
        // 缓存中已经有key了, 更新即可
        if (hash.count(key) == 1) {
            // 将最活跃的元素从当前位置删除
            auto t = hash[key];
            t->prev->next = t->next;
            t->next->prev = t->prev;
            
            // 将最活跃的元素添加到表头
            t->next = head->next;
            t->prev = head;
            head->next->prev = t;
            head->next = t;

            // 更新其值
            hash[key]->val = value;
        } else { // 没有此key, 则添加

            // 如果LRU满了, 要删除最不活跃的元素
            if (this->cap == this->cnt) {
                // 将最不活跃的表尾元素从哈希表和链表删除
                hash.erase(tail->prev->key);
                tail->prev->prev->next = tail;
                tail->prev = tail->prev->prev;
            } else {
                this->cnt++;
            }

            // 将新元素添加到哈希表
            auto t = new MyNode({key, value, NULL, NULL});
            hash[key] = t;

            // 将新元素添加到表头
            t->next = head->next;
            t->prev = head;
            head->next->prev = t;
            head->next = t;
        }
    }
};

