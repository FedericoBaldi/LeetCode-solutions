-- https://leetcode.com/problems/count-salary-categories
SELECT "Low Salary" as category,
    SUM(income < 20000) as accounts_count
FROM Accounts
UNION ALL
SELECT "Average Salary" as category,
    SUM(income BETWEEN 20000 and 50000) as category 
FROM Accounts
UNION ALL
SELECT "High Salary" as category,
        SUM(income > 50000) as accounts_count
FROM Accounts
