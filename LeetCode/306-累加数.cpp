#include "LeetCode.h"

class Solution {
public:
    long long n;
    bool isAdditiveNumber(string num)
    {
        n = num.size();

        //特判0开头
        if(num[0] == '0')
        {
            for(long long i = 1; i < n - 1; i++)
            {
                auto t = num.substr(1, i);
                long long second;
                stringstream ss;
                ss << t;
                ss >> second;
                ss.clear();
                if(judge(0, second, num, i + 1))
                    return true;
            }
            return false;
        }

        //i是第一个数字的结束位置, j是第二个数字的结束位置
        for(long long i = 0; i < n - 2; i++)
            for(long long j = i + 1; j < n - 1; j++)
            {
                long long first, second;
                stringstream ss;
                auto t = num.substr(0, i + 1);
                ss << t;
                ss >> first;
                ss.clear();
                t = num.substr(i + 1, j - i);
                ss << t;
                ss >> second;
                ss.clear();
                if(num[i + 1] == '0')
                {
                    if(judge(first, 0, num, j + 1))
                        return true;
                    j = n;
                    continue;
                }

                if(judge(first, second, num, j + 1))
                    return true;
            }

        return false;
    }

    bool judge(long long first, long long second, const string &num, long long pos)
    {
        while(true)
        {
            long long t = first + second;
            auto s = to_string(t);
            long long len = s.size();
            if(len + pos > n)
                return false;

            for(long long i = 0; i < len; i++)
                if(num[i + pos] != s[i])
                    return false;


            first = second;
            second = t;
            pos += len;

            if(pos == n)
                return true;
        }

        return true;
    }
};