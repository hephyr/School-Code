SELECT Reader.readerNo, readerName, Book.bookNo, bookName
FROM Reader, Book, Borrow
WHERE year(borrowDate) BETWEEN 2007 AND 2008
AND Book.bookNo = Borrow.bookNo
AND Borrow.readerNo = Reader.readerNo