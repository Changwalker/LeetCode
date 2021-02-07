/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1.枚举
    // bool judge(int n){
    //     for(int i = 2; i*i <= n; ++i){
    //         if(n % i == 0)
    //             return false;
    //     }
    //     return true;
    // }
    // int countPrimes(int n) {
    //     int res = 0;
    //     for(int i = 2; i < n; ++i){
    //         if(judge(i))
    //             res++;
    //     }
    //     return res;
    // }
    int countPrimes(int n) {
        // 2. 埃氏筛
        vector<int> isPrime(n,1);
        int res = 0;
        for(int i = 2; i < n; ++i){
            if(isPrime[i]){
                res ++;
                if((long long)i * i < n){
                    // 从 2x 开始标记其实是冗余的，应该直接从 x⋅x 开始标记，
                    // 因为 2x,3x... 这些数一定在 x⋅x 之前就被其他数的倍数标记过了
                    for(int j = 2*i; j < n; j += i)
                        isPrime[j] = 0;
                }
            }
        }
        return res;
    }
};
// @lc code=end

