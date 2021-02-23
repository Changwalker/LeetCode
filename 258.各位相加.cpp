/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        if(num < 10) 
            return num;
        
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return addDigits(sum);
    }
};
// @lc code=end

