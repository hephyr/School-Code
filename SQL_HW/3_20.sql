SELECT Reader.readerNo, readerName, workUnit
FROM Borrow, Reader
WHERE bookNo IN (SELECT bookNo
                    FROM Borrow, Reader
                    WHERE readerName = '马永强'
                    AND Borrow.readerNo = Reader.readerNo
                )
AND Borrow.readerNo = Reader.readerNo
GROUP BY Reader.readerNo, readerName, workUnit