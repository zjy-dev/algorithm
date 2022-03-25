-- 1. 自连接
-- 2. 筛选日期早于自己的记录
-- 3. 分组查询

SELECT
    a1.player_id, a1.event_date, sum(a2.games_played) as games_played_so_far
FROM 
    Activity as a1
INNER JOIN
    Activity as a2
WHERE 
    a1.player_id = a2.player_id
AND
    a1.event_date >= a2.event_date
GROUP BY
    a1.player_id, a1.event_date

