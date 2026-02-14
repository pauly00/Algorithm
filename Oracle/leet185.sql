# Write your MySQL query statement below
SELECT Department, Employee, Salary
FROM (
         SELECT
             d.name as Department,
             e.name as Employee,
             e.salary as Salary,
             DENSE_RANK() OVER (
            PARTITION BY d.id-- 부서 관리
            ORDER BY Salary-- 순위 결정
            DESC
        ) ranking
         FROM Employee e
                  JOIN Department d
                       ON e.departmentId = d.id
     ) t -- 이름표 규칙
WHERE ranking <= 3;