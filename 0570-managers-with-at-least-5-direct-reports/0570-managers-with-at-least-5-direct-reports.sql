# Write your MySQL query statement below
select a.name
from Employee as e
inner join Employee as a
on e.managerId = a.id
group by a.id
having count(a.id)>=5;