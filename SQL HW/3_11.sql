SELECT classNo, MAX(price) AS max_price, AVG(price) AS avg_price
FROM Book
GROUP BY classNo
ORDER BY MAX(price) DESC