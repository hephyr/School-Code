UPDATE Borrow
SET returnDate = getdate()
FROM Borrow x
WHERE EXISTS
        (SELECT *
        FROM Reader
        WHERE x.readerNo = Reader.readerNo 
        AND datediff(year,convert(datetime,(substring(identitycard,7,8))),getdate()) BETWEEN 25 AND 35
        )
AND Borrow.readerNo = Reader.readerNo