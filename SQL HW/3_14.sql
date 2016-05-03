SELECT readerName, workUnit
FROM Reader
WHERE readerNo NOT IN (SELECT readerNo FROM Borrow WHERE returnDate IS NULL)