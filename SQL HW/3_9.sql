SELECT Reader.readerNo, readerName, bookName, borrowDate, returnDate
FROM Reader, Book, Borrow
WHERE publishingName = '清华大学出版社'
AND Reader.readerNo = Borrow.readerNo
AND Borrow.bookNo = Book.bookNo