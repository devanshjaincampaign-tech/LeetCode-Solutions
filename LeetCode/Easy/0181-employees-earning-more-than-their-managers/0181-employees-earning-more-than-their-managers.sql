# Write your MySQL query statement below
SELECT e.name as Employee
FROM Employee e
JOIN Employee m
    on e.managerId=m.id
    WHERE e.salary>m.salary;

    /*
===========================================================
                  SELF JOIN IN SQL
===========================================================

WHAT IS A SELF JOIN?
--------------------
A SELF JOIN means joining a table with ITSELF.

It is useful when rows in the same table have a
relationship with other rows in that same table.

Example:
    Employee table contains both:
        - Employee information
        - Manager information

There is no separate Manager table.

Therefore, we use Employee twice.


-----------------------------------------------------------
EMPLOYEE TABLE
-----------------------------------------------------------

+----+-------+--------+-----------+
| id | name  | salary | managerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | NULL      |
| 4  | Max   | 90000  | NULL      |
+----+-------+--------+-----------+

For Joe:
    Joe's id       = 1
    Joe's salary   = 70000
    Joe's managerId = 3

managerId = 3 means:
    Joe's manager is the employee whose id = 3.

Employee with id = 3:
    Sam
    salary = 60000


-----------------------------------------------------------
HOW SELF JOIN WORKS
-----------------------------------------------------------

We use the Employee table TWO times:

    Employee e
        ↓
    represents the EMPLOYEE

    Employee m
        ↓
    represents the MANAGER


Query:
-------
SELECT e.name AS Employee
FROM Employee e
JOIN Employee m
    ON e.managerId = m.id
WHERE e.salary > m.salary;


Here:

    e = Employee
    m = Manager

Even though both e and m come from the SAME table,
the aliases allow us to treat them as two different
roles.


-----------------------------------------------------------
THE JOIN CONDITION
-----------------------------------------------------------

ON e.managerId = m.id

This means:

    Employee's managerId
             =
    Manager's id


Example:

    Joe's managerId = 3

SQL searches for:

    Employee with id = 3

It finds:

    Sam


So SQL creates a relationship:

    Joe ─────────→ Sam
    Employee       Manager


-----------------------------------------------------------
SALARY COMPARISON
-----------------------------------------------------------

WHERE e.salary > m.salary

Here:

    e.salary = Employee's salary
    m.salary = Manager's salary

For Joe:

    70000 > 60000

Therefore:

    TRUE → Joe is returned.


For Henry:

    Henry salary = 80000
    Max salary   = 90000

    80000 > 90000

    FALSE → Henry is NOT returned.


-----------------------------------------------------------
WHY USE JOIN INSTEAD OF JUST SELECTING?
-----------------------------------------------------------

The employee's manager is identified using managerId.

For example:

    Employee:
    id = 1
    managerId = 3

We need to find:

    Who has id = 3?

That information exists in the SAME Employee table.

Therefore, we join Employee with itself:

    Employee e
        JOIN
    Employee m


-----------------------------------------------------------
STEP-BY-STEP LOGIC
-----------------------------------------------------------

1. Take an employee.

2. Look at their managerId.

3. Find the Employee whose id equals that managerId.

4. Treat that employee as the manager.

5. Compare:
       employee salary
       vs
       manager salary

6. If:
       employee salary > manager salary

   return the employee's name.


-----------------------------------------------------------
FINAL QUERY
-----------------------------------------------------------

SELECT e.name AS Employee
FROM Employee e
JOIN Employee m
    ON e.managerId = m.id
WHERE e.salary > m.salary;


-----------------------------------------------------------
MEMORY TRICK
-----------------------------------------------------------

SELF JOIN
    =
JOIN A TABLE WITH ITSELF

In this problem:

    e → Employee
    m → Manager

Relationship:

    e.managerId = m.id

Comparison:

    e.salary > m.salary


Think:

    "Find my manager, then compare our salaries."


===========================================================
IMPORTANT SQL CONCEPTS USED
===========================================================

1. SELF JOIN
   → Employee joined with Employee.

2. ALIAS
   → e and m give two different roles to the same table.

3. ON
   → Defines how employee and manager are connected.

4. WHERE
   → Filters employees whose salary is greater.

5. AS
   → Renames e.name to Employee in the result.

===========================================================
*/