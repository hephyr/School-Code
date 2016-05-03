SELECT bookNo, publishingDate, shopDate, bookName
FROM Book
WHERE year(shopDate) BETWEEN 2005 AND 2008