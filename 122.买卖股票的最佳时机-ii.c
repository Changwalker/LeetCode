/*
 * @lc app=leetcode.cn id=122 lang=c
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start


int maxProfit(int* prices, int pricesSize){
    int ans = 0;
    for(int i = 0;i < pricesSize ; i++)
    {
        ans += fmax(0,prices[i]-prices[i-1]);
    }
    return ans;
}


// @lc code=end

