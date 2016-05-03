SELECT Reader.readerNo, readerName, bookName, borrowDate
FROM Reader, Book, Borrow
WHERE Reader.readerNo IN (
                        SELECT readerNo
                        FROM Borrow
                        WHERE bookNo = '007'
                        AND returnDate IS NULL
                        )
AND returnDate IS NOT NULL
AND Reader.readerNo = Borrow.readerNo
AND Borrow.bookNo = Book.bookNo