/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1)
            return false;
        while(n % 3 == 0){
            n /= 3;
        }
        return n == 1;
    }
};
// @lc code=end

