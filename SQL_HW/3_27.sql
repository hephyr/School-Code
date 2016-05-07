CREATE VIEW richreader
AS
    SELECT Reader.readerNo, readerName, sum(price)
    FROM Reader, Borrow, Book
    WHERE Reader.readerNo = Borrow.readerNo
    AND Borrow.bookNo = Book.bookNo
    GROUP BY Reader.readerNo, readerName
    HAVING sum(price) >= 150