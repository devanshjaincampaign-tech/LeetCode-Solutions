# Write your MySQL query statement below
SELECT 
p.firstName,
p.lastName,
a.city,
a.state
FROM Person p
LEFT JOIN Address a
on p.personId=a.personId;

/*
===========================================================
                    LEFT JOIN IN SQL
===========================================================

WHAT IS LEFT JOIN?
------------------
LEFT JOIN combines two tables and returns:

1. ALL rows from the LEFT table.
2. Matching rows from the RIGHT table.
3. If no matching row exists in the RIGHT table,
   SQL returns NULL for the RIGHT table's columns.

SYNTAX:
--------
SELECT columns
FROM LeftTable
LEFT JOIN RightTable
    ON LeftTable.key = RightTable.key;


IMPORTANT RULE:
---------------
LEFT JOIN = "KEEP EVERYTHING FROM THE LEFT TABLE"

The LEFT table is the table written BEFORE LEFT JOIN.

Example:
--------
FROM Person p
LEFT JOIN Address a
    ON p.personId = a.personId;

Here:
    Person  → LEFT table → ALL persons are preserved
    Address → RIGHT table → only matching addresses are added


WHY DO WE USE LEFT JOIN?
------------------------
Use LEFT JOIN when you want every record from one table,
even if there is no corresponding record in the other table.

Typical requirement:
"Show ALL customers, even customers who have no orders."

That requires:
    Customers LEFT JOIN Orders


EXAMPLE:
--------
Person:
+----------+-----------+
| personId | name      |
+----------+-----------+
| 1        | Allen     |
| 2        | Bob       |
| 3        | John      |
+----------+-----------+

Address:
+----------+-------------+
| personId | city        |
+----------+-------------+
| 1        | New York    |
| 3        | Boston      |
+----------+-------------+

Query:
-------
SELECT p.name, a.city
FROM Person p
LEFT JOIN Address a
    ON p.personId = a.personId;

Result:
-------
+-------+----------+
| name  | city     |
+-------+----------+
| Allen | New York |
| Bob   | NULL     |
| John  | Boston   |
+-------+----------+

WHY IS BOB PRESENT?
-------------------
Bob does not have an address.

But LEFT JOIN says:
"Keep EVERY row from Person."

Therefore Bob remains in the result.

Since Bob has no matching row in Address:
    city = NULL


LEFT JOIN vs INNER JOIN:
-----------------------

INNER JOIN:
    Returns ONLY rows that have a match in BOTH tables.

LEFT JOIN:
    Returns ALL rows from the LEFT table,
    plus matching rows from the RIGHT table.

Example:

Person LEFT JOIN Address
        ↓
    Every Person
        +
    Address if available
        +
    NULL if unavailable


VISUAL:
--------
        LEFT TABLE                 RIGHT TABLE
          Person                    Address
             │                         │
             │      LEFT JOIN          │
             └─────────────────────────┘
                    ↓
              KEEP ALL Person
                    +
             MATCH Address
                    +
             NULL if no match


THE ON CONDITION:
-----------------
The ON condition tells SQL HOW to match rows.

Example:
    ON p.personId = a.personId

This means:
    Match a Person with an Address
    when their personId values are equal.


ALIASES:
--------
p and a are aliases.

    Person p
        ↓
    p.firstName

    Address a
        ↓
    a.city

Aliases make queries shorter and easier to read.


RIGHT JOIN:
-----------
RIGHT JOIN is the opposite of LEFT JOIN.

    A LEFT JOIN B
        → Keep everything from A

    A RIGHT JOIN B
        → Keep everything from B

In practice, LEFT JOIN is used more often because
a RIGHT JOIN can usually be rewritten by swapping
the order of the tables.


MEMORY TRICK:
-------------
LEFT JOIN = "PROTECT THE LEFT TABLE"

Whatever table comes BEFORE LEFT JOIN:
    → ALL of its rows are preserved.

Whatever table comes AFTER LEFT JOIN:
    → Only matching rows are included.
    → Otherwise its columns become NULL.


FOR YOUR LEETCODE PROBLEM:
--------------------------
The requirement says:

"Report ... each person in the Person table.
If the address is not present, report NULL."

The important phrase is:
    "each person"

Therefore:
    Person must be preserved.

So we use:

    Person LEFT JOIN Address

Query:
-------
SELECT p.firstName,
       p.lastName,
       a.city,
       a.state
FROM Person p
LEFT JOIN Address a
    ON p.personId = a.personId;

===========================================================
QUICK SUMMARY
===========================================================

LEFT JOIN
    ↓
Keep ALL rows from the LEFT table
    +
Get matching rows from RIGHT table
    +
If no match → NULL

Remember:

    LEFT JOIN = ALL LEFT + MATCHING RIGHT

===========================================================
*/