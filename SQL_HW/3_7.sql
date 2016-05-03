SELECT Borrow.bookNo, Book.bookName, Borrow.returnDate
FROM Borrow, Book, Reader
WHERE Borrow.bookNo = Book.bookNo AND Reader.readerName = '马永强' AND Borrow.readerNo = Reader.readerNo