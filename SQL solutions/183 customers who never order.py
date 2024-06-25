-- https://leetcode.com/problems/customers-who-never-order
SELECT name as Customers
FROM Customers 
LEFT OUTER JOIN Orders
ON Customers.id = Orders.customerId
WHERE Orders.customerId is NULL;

