#include "LeetCode.h"

/**
 * 时间复杂度 -> O(n), 遍历一遍即可, 指针不回头
 * 空间复杂度 -> O(1)
 */
class Solution {
public:
  bool isNumber(string s) {
    // s的长度大于等于1, 无需特判空串

    int n = s.size();

    // 读取用的指针, 不回头
    int idx = 0;

    // 1. 去掉首部空格
    while (s[idx] == ' ') {
      idx++;
    }

    // 2. 读取科学计数法的前半部分(没用科学计数法就是读取全部数值)
    // 读到的东西不是小数或整数就返回false

    // 2.1 读取一个整数
    // 这个整数可能是科学计数法的前半部分, 也可能只是小数的整数部分,
    // 或者是空的也没问题 flag会记录是否读取到了整数
    bool flag = readInt(s, idx);

    // 2.2 如果有小数点存在, 那么小数点前后只要一个部分有数字就可以了,
    // 使用或运算进行判断
    if (s[idx] == '.') {
      idx++;
      // 小数点后面不能有负数, 使用readUInt
      flag = readUInt(s, idx) || flag;
    }

    // 2.3 读不到整数或小数, 返回false
    if (flag == false) {
      return false;
    }

    // 3. 判断是否使用了科学计数法, 如果使用了就读取一个整数
    // 读不到想要的整数就返回false
    if (s[idx] == 'e' || s[idx] == 'E') {
      idx++;
      bool flag = readInt(s, idx);
      if (flag == false) {
        return false;
      }
    }

    // 4. 程序能运行到这里, 说明没使用科学计数法或者科学计数法格式合法
    // 剩下的内容必须全部是空格, 只要写一个非常简单的判断逻辑即可
    while (idx < n) {
      if (s[idx] != ' ') {
        return false;
      }
      idx++;
    }

    return true;
  }

  // 读取一个整数, 并将指针移动到整数结束的下一个位置
  bool readInt(const string &s, int &idx) {
    if (s[idx] == '+' || s[idx] == '-') {
      idx++;
    }

    return readUInt(s, idx);
  }

  // 读取一个非负整数, 并将指针移动到非负整数结束的下一个位置
  bool readUInt(const string &s, int &idx) {
    int cnt = 0;
    while (s[idx] >= '0' && s[idx] <= '9') {
      idx++;
      cnt++;
    }

    return cnt > 0;
  }
};
