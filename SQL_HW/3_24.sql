SELECT Reader.readerNo, readerName, substring(identitycard, 7, 8) as birthday
FROM Reader, Borrow, Book
WHERE Reader.readerNo=Borrow.readerNo 
AND Borrow.bookNo=Book.bookNo
GROUP BY Reader.readerNo, readerName, substring(identitycard, 7, 8)
HAVING sum(price) = (SELECT max(sumprice)
                        FROM (SELECT sum(price)sumprice
                                FROM Borrow, Book
                                WHERE Borrow.bookNo = Book.bookNo
                                GROUP BY readerNo
                            ) x
                    )