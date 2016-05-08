UPDATE Book
SET price = price * (1 - 0.05)
FROM Book
WHERE shopNum = (SELECT max(shopNum)
                FROM Book) 