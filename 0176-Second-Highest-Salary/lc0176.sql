/*  Write your MySQL query statement below */

/* Solution 1 */
SELECT (SELECT DISTINCT `Salary` FROM `Employee`
        ORDER BY `Salary` DESC
        LIMIT 1 OFFSET 1) AS `SecondHighestSalary`


/* Solution 2 */
SELECT MAX(`Salary`) AS `SecondHighestSalary` FROM `Employee`
    WHERE `Salary` < (SELECT MAX(`Salary`) FROM `Employee`)