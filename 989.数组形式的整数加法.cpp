/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        int i = A.size() - 1;
        int sum = 0, carry = 0;       
        while(i >= 0 || K != 0){
            int x = i >= 0 ? A[i] : 0;
            int y = K != 0 ? K%10 : 0;
            sum = x + y + carry;
            
            carry = sum / 10;//进位一定在sum%=10 之前
            sum %= 10;
            K /= 10;
            res.push_back(sum);
            i--;
        }
        //到最后看还有进位吗
        if(carry != 0)
            res.push_back(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

