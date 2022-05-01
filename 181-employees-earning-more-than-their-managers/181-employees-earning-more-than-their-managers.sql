# Write your MySQL query statement below
select ma.name as Employee
from employee em
join employee ma
on  em.id = ma.managerId
where ma.managerId is not NULL
and em.salary < ma.salary
