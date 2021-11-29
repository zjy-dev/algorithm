#include"LeetCode.h"

struct MyNode
{
    int key, val;
    MyNode* next;
    MyNode* prev;
};

class LRUCache {
public:
    unordered_map<int, MyNode*> hash;
    MyNode* head;
    MyNode* tail;
    int cap;

    LRUCache(int capacity) {
        this->cap = capacity;
        this->head = new MyNode({0, 0, NULL, NULL});
        this->tail = new MyNode({0, 0, NULL, NULL});
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!hash.count(key))
            return -1;
        
        auto val = hash[key];

        //delete
        val->prev->next = val->next;
        val->next->prev = val->prev;

        //addAtTail
        val->prev = tail->prev;
        val->next = tail;
        val->prev->next = val;
        tail->prev = val;

        return val->val;
    }
    
    void put(int key, int value) {
        MyNode* val;
        if(hash.count(key))
        {
            val = hash[key];
            val->val = value;
            val->prev->next = val->next;
            val->next->prev = val->prev;
        }
        else
        {
            if(this->cap == this->hash.size())
            {
                cout << "value = " << this->head->next->val << endl;
                hash.erase(this->head->next->key);
                head->next = head->next->next;
                head->next->prev = head;
            }
            val = new MyNode({key, value});
            hash[key] = val;
        }
        
        //addAtTail
        val->prev = tail->prev;
        val->next = tail;
        val->prev->next = val;
        tail->prev = val;
    }
};
