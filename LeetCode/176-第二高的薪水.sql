-- ifnull(a, b), 如果a非空返回a, 否则返回b

select ifnull (
    (select 
        distinct salary
    from employee
    order by salary desc
    limit 1 offset 1),
    null
) as SecondHighestSalary
