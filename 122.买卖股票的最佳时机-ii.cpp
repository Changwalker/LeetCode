/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        //交易次数不受限，把所有的上坡全部收集到，一定是利益最大化的
        for(int i = 1;i < prices.size() ; i++)
        {
            ans += max(0,prices[i]-prices[i-1]);
        }
        return ans;
    }
};
// @lc code=end

