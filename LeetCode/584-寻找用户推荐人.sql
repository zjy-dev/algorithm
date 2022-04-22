select name
from customer 
where isNull(referee_id) or referee_id != 2