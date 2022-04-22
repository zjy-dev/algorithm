select customer_id, count(*) as count_no_trans 
from visits as v
left join transactions as t
on v.visit_id = t.visit_id
where transaction_id is null
group by customer_id