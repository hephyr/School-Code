SELECT Reader.readerNo, readerName, workUnit, Borrow.bookNo, bookName, borrowDate
FROM Book, Borrow, Reader
WHERE Reader.readerNo IN (SELECT readerNo
                            FROM Borrow
                            WHERE year(borrowDate) BETWEEN 2005 AND 2008
                            AND returnDate IS NULL
                        )
AND Reader.readerNo = Borrow.readerNo
AND Borrow.bookNo = Book.bookNo