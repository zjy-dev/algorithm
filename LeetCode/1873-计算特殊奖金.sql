-- if
select employee_id, if (
    employee_id & 1 = 1 and name not like 'M%',
    salary,
    0
) as bonus
from employees
order by employee_id

-- case
select employee_id, (
    case
    when name not like 'M%' and employee_id & 1 = 1 then salary
    else 0
    end
) as bonus
from employees
order by employee_id