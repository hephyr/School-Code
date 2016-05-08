UPDATE Book
SET price = price * (1 + 0.1)
FROM Book, BookClass
WHERE className = '经济管理'
AND Book.classNo = BookClass.classNo