SELECT Reader.readerNo, readerName, bookName, borrowDate
FROM Reader, Borrow, Book
WHERE Reader.readerNo NOT IN (
                    SELECT readerNo
                    FROM Borrow
                    WHERE bookNo = '001')
AND Reader.readerNo = Borrow.readerNo
AND Borrow.bookNo = Book.bookNo