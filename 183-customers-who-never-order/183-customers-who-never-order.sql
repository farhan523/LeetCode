select name as Customers
from Customers c 
left join  orders o
on c.id = o.customerid
where o.customerid is null
