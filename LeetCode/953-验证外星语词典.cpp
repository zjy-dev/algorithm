#include"LeetCode.h"

class Solution{
public:
    unordered_map<char, int> hash;
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < 26; i++)
            hash[order[i]] = i;
        
        for(int i = 0; i < words.size() - 1; i++)
            if(!isOrdered(words[i], words[i + 1]))
                return false;
        return true;
    }

    bool isOrdered(const string& s1, const string& s2)
    {
        for(int i = 0; i < min(s1.size(), s2.size()); i++)
            if(hash[s1[i]] > hash[s2[i]])
                return false;
            else if(hash[s1[i]] < hash[s2[i]])
                return true;
                
        return s1.size() <= s2.size();
    }
};