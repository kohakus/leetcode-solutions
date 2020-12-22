/* Write your MySQL query statement below */

/* Solution 1 */
SELECT `Score`, (SELECT COUNT(*) FROM (SELECT DISTINCT `Score` s FROM `Scores`) `Unique`
                    WHERE s >= `Score`) `Rank` FROM `Scores`
ORDER BY `Score` DESC


/* Solution 2 */
SELECT `Score`, DENSE_RANK() OVER (ORDER BY `Score` DESC) AS `Rank` FROM `Scores`