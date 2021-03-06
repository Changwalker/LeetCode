/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1)
            return false;
        while(n % 4 == 0){
            n /= 4;
        }
        return n == 1;
    }
};
// @lc code=end

