select 
    ad_id, 
    ifnull(round(100 * sum(action = "clicked") / 
        (sum(action = "viewed") + sum(action = "clicked")), 2),
    0) as ctr
from ads
group by ad_id
order by ctr desc, ad_id asc