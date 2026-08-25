SELECT name AS Customers
FROM Customers
WHERE id NOT IN (
    SELECT customerId 
    FROM Orders 
    WHERE customerId IS NOT NULL
);