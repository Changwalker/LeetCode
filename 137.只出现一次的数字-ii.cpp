/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 1.利用set
        // 3×(a+b+c)−(a+a+a+b+b+b+c) = 2c
        set<int> s;
        long sumset = 0 , sumarray = 0;
        for(auto a : nums){
            sumarray += a;
            s.insert(a);
        }
        for(auto a : s)
            sumset += a;       
        return (int)((3*sumset - sumarray) / 2);

        
        // 2.位运算
        // 区分出现一次的数字和出现三次的数字，
        // 使用两个位掩码：seen_once 和 seen_twice。

        // 思路是：
        // 仅当 seen_twice 未变时，改变 seen_once。
        // 仅当 seen_once 未变时，改变seen_twice。
        /*
        first appearence: 
        add num to seen_once 
        don't add to seen_twice because of presence in seen_once

        second appearance: 
        remove num from seen_once 
        add num to seen_twice

        third appearance: 
        don't add to seen_once because of presence in seen_twice
        remove num from seen_twice
        */


    //     int seenOnce = 0, seenTwice = 0;
    //     for (auto num : nums) {
    //         seenOnce = ~seenTwice & (seenOnce ^ num);
    //         seenTwice = ~seenOnce & (seenTwice ^ num);
    //     }
    // return seenOnce;
    }
};
// @lc code=end

