/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (25.10%)
 * Total Accepted:    6.2K
 * Total Submissions: 24.6K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */
// #include "com.h"
// using namespace std;
class Solution
{
  public:
    int longestValidParentheses(string s)
    {
#define max_n 50000
        struct parenth
        {
            int index;
            char val;
            parenth(int index, char val) : index(index), val(val) {}
        };

        int dp[max_n], lv = 0;
        stack<parenth> sk;
        memset(dp, 0, max_n);
        if (!s.size())
            return 0;
        sk.push(parenth(0, s[0]));
        for (auto i = 1; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                sk.push(parenth(i, s[i]));
            }
            else
            {
                if (sk.size() && sk.top().val == '(')
                {
                    auto p = sk.top();
                    sk.pop();
                    if (p.index - 1 >= 0)
                        dp[i] = dp[i - 1] + dp[p.index - 1] + 2;
                    else
                        dp[i] = dp[i - 1] + 2;
                    lv = dp[i] > lv ? dp[i] : lv;
                    continue;
                }
                else
                {
                    sk.push(parenth(i, s[i]));
                }
                
            }
        }
        return lv;
    }
};
