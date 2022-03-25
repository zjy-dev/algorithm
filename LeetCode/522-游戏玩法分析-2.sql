-- 下面这样的写法思路是正确的, 结果是错误的, 因为min(event_date)和device_id无关, device_id会取第一条数据
-- SELECT
--     player_id, device_id
-- FROM 
--     (
--         SELECT 
--             player_id, device_id, min(event_date)
--         FROM
--             Activity
--         GROUP BY
--             player_id
--     ) AS temp

SELECT
    player_id, device_id
FROM
    Activity as a1
WHERE
    (a1.player_id, a1.event_date) IN
    ( 
        SELECT
            player_id, min(event_date) as event_date
        FROM
            Activity as a2
        GROUP BY
            player_id
    )