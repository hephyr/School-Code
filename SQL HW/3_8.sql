SELECT Reader.readerNo, readerName, bookName, borrowDate, shouldDate
FROM Reader, Book, Borrow
WHERE workUnit='会计学院' AND returnDate IS NULL
AND Reader.readerNo = Borrow.readerNo
AND Borrow.bookNo = Book.bookNo