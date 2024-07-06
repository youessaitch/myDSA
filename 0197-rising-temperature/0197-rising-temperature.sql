# Write your MySQL query statement below
SELECT id
from Weather w1
where temperature > (
    select temperature 
    from Weather w2
    where w2.recordDate = DATE_SUB(w1.recordDate, INTERVAL 1 DAY)
);