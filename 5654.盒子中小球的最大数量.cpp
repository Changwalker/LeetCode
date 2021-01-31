/*
你在一家生产小球的玩具厂工作，有 n 个小球，编号从 lowLimit 开始，到 highLimit 结束（包括 lowLimit 和 highLimit ，即 n == highLimit - lowLimit + 1）。
另有无限数量的盒子，编号从 1 到 infinity 。

你的工作是将每个小球放入盒子中，其中盒子的编号应当等于小球编号上每位数字的和。
例如，编号 321 的小球应当放入编号 3 + 2 + 1 = 6 的盒子，而编号 10 的小球应当放入编号 1 + 0 = 1 的盒子。

给你两个整数 lowLimit 和 highLimit ，返回放有最多小球的盒子中的小球数量。
如果有多个盒子都满足放有最多小球，只需返回其中任一盒子的小球数量。
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBalls(int l, int h) {
        vector<int> sum(50); //1 <= lowLimit <= highLimit <= 10^5各位和最大为45(99999)
        int res = 0;
        for(int i = l; i <= h; ++i){
            int x = i;
            int s = 0;
            while(x){        //计算编号各位和s
                s += x % 10;
                x /= 10;
            } 
            sum[s] ++ ;
            res = max(res,sum[s]);
        }
        return res;
    }
};