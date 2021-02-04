# Write your MySQL query statement below
select(
    select distinct salary
    from employee
    order by salary desc
    limit 1,1 #limit 偏移量,返回行数
)
as SecondHighestSalary