-- where后面的两个条件
-- 第一个确保连续的两天
-- 第二个确保是首天

select 
    round(
    count(a.player_id) / 
    (select count(distinct player_id) from activity),
    2) as fraction
from activity as a
inner join activity as b
on a.player_id = b.player_id
where datediff(b.event_date, a.event_date) = 1
and (a.player_id, a.event_date) in (
    select player_id, min(event_date)
    from activity
    group by player_id
) 

