-- group_concat可以把一组里的内容拼接起来作为一项

select 
    sell_date, 
    count(distinct product) as num_sold, 
    group_concat(distinct product) as products
from activities
group by sell_date
order by sell_date