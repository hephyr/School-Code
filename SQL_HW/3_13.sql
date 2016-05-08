SELECT Reader.readerNo, readerName, Book.bookNo, bookName
FROM Book, Reader, Borrow x
WHERE Book.bookNo = x.bookNo
AND x.readerNo = Reader.readerNo 
AND EXISTS
    (SELECT *
        FROM Borrow
        WHERE year(borrowDate) BETWEEN 2007 AND 2008
    )