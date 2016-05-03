SELECT COUNT(bookNo) AS count_num
FROM Book
GROUP BY classNo
HAVING classNo < '009'