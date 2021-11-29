#include"LeetCode.h"

class MovingAverage {
public:
    queue<int> q;
    int size, sum = 0;

    MovingAverage(int size) 
    {
        this->size = size;
    }
    
    double next(int val) 
    {
        sum += val;
        q.push(val);
        
        if(q.size() > this->size)
            sum -= q.front(), q.pop();
        
        return sum / q.size();
    }
};