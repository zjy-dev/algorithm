select employee_id
from (
    select employee_id from employees
    union all
    select employee_id from salaries
) as t
group by employee_id
having count(employee_id) < 2
order by employee_id