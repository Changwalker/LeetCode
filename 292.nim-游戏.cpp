/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution {
public:
    // 巴什博弈:只有一堆n个物品，两个人轮流从这堆物品中取物， 
    // 规定每次至少取一个，最多取m个。最后取光者得胜。 
    // 只要 n 不能整除 m+1 ,那么必然是先手取胜，否则后手取胜 
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
// @lc code=end

