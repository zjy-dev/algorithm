select firstName, lastName, city, state
from address as a
right join person as p
on p.personId = a.personId
