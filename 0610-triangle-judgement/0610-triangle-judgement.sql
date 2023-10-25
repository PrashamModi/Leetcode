# Write your MySQL query statement below
Select x, y, z ,
CASE
When x + y > z
AND y + z > x 
AND x + z > y THEN 'Yes'
else 'No'
END as triangle
From Triangle;