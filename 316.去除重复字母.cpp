/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26), num(26);
        // 初始化字母出现次数哈希表
        for(char ch : s){
            num[ch - 'a']++;
        }

        string stack;
        // 遍历字符串s
        for(char ch : s){ //    s="bcacc"
            //若该位置字母没有在栈中出现过
            if(!vis[ch - 'a']){
                // 栈不为空 && 栈顶元素字典序列比当前字母靠后(字典序可调整)

                while(!stack.empty() && stack.back() > ch){
                    // 栈顶元素还有剩余出现次数 即还会再出现
                    if(num[stack.back() - 'a'] > 0){
                        vis[stack.back() - 'a'] = 0; //修改栈顶元素出现状态 表明栈中无该元素
                        stack.pop_back();            //栈顶元素(还会出现的字母)弹出(此处上下两句不能调换！)
                    }
                    else 
                        break;
                }
                stack.push_back(ch);//该位置字母压栈 b bc ba bac
                vis[ch - 'a'] = 1;  //修改出现状态 表明当前栈中有该元素
            }
            num[ch - 'a'] -=1; //遍历过的字母出现次数减一
        }
        return stack;
    }
};
// @lc code=end