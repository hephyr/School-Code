SELECT y.readerNo, readerName, x.bookNo, bookName
FROM Book x, Reader y, Borrow z
WHERE x.bookNo = z.bookNo
AND z.readerNo = y.readerNo
AND EXISTS
        (SELECT readerNo
        FROM Borrow
        GROUP BY readerNo
        HAVING y.readerNo = Borrow.readerNo
        AND COUNT(*) >= 3
        )