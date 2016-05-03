SELECT readerName, borrowDate, shouldDate
FROM Reader, Borrow
WHERE bookNo = '001-000029'