select
    p.firstName, p.lastName, a.city, a.state
from
    address a 
right join 
    person p
on 
    a.personId = p.personId;