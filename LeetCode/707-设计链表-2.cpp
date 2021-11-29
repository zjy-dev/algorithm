#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* next, *pre;
    int val;
};

class MyLinkedList {
private:
    Node* head, *tail;
    int size;
public:
    MyLinkedList() 
    {
        this->head = new Node({NULL, NULL, 0}); 
        this->tail = new Node({NULL, NULL, 0}); 
        head->next = tail;
        tail->pre = head;
        this->size = 0;
    }
    
    int get(int index) 
    {
        if(index < 0 or index >= this->size)
            return -1;
        auto p = this->head;

        while(index-- >= 0)
            p = p->next;

        return p->val;
    }
    
    void addAtHead(int val) 
    {
        head->next = new Node({head->next, head, val});
        head->next->next->pre = head->next;
        this->size++;
    }

    void addAtTail(int val) 
    {
        tail->pre = new Node({tail, tail->pre, val});
        tail->pre->pre->next = tail->pre;
        this->size++;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index < 0 or index > this->size)
            return;
        
        auto p = this->head;

        while(index--)
            p = p->next;
        
        p->next = new Node({p->next, p, val});
        p->next->next->pre = p->next;
        
        this->size++;
    }
    
    void deleteAtIndex(int index)
    {
        if(index < 0 or index >= this->size)
            return;
        auto p = this->head;

        while(index--)
            p = p->next;
        p->next = p->next->next;
        p->next->pre = p;
        this->size--;
    }
};




