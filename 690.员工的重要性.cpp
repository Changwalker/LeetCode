/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector <int> subordinates;
};


class Solution {
public:
    unordered_map<int, Employee *> mp;
    int dfs(int id){
        Employee *e = mp[id];
        int sum = e->importance;
        for(int subid : e->subordinates){
            sum += dfs(subid);
        }
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto &x : employees){
            mp[x->id] = x;
        }
        return dfs(id);
    }
};
// @lc code=end

