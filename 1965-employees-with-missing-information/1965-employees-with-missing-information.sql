# Write your MySQL query statement below
select em.employee_id from 
employees em
left join salaries sa
on em.employee_id = sa.employee_id
where em.employee_id is null or sa.employee_id is null

union

select sal.employee_id from 
salaries sal
left  join employees emp
on emp.employee_id = sal.employee_id
where emp.employee_id is null or sal.employee_id is null

order by employee_id