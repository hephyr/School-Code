SELECT Reader.readerNo, readerName, workUnit, Borrow.bookNo, bookName, borrowDate
FROM Book, Reader, Borrow
WHERE Reader.readerNo IN (SELECT readerNo FROM Borrow, Book WHERE bookName = '离散数学' AND Borrow.bookNo = Book.bookNo)
AND Reader.readerNo IN (SELECT readerNo FROM Borrow, Book WHERE bookName = '数据库系统概念' AND Borrow.bookNo = Book.bookNo)
AND (bookName = '离散数学' or bookName = '数据库系统概念')
AND Book.bookNo = Borrow.bookNo
AND Borrow.readerNo = Reader.readerNo