select id, (
    case
    when isNull(p_id) then "Root"
    when id in (select p_id from tree) then "Inner"
    else "Leaf"
    end
) as type
from tree
order by id