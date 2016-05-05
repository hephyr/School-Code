SELECT Reader.readerNo,readerName,bookName,borrowDate
FROM Borrow,Reader,Book
WHERE Borrow.readerNo IN (SELECT Borrow.readerNo FROM Borrow,Book WHERE classNo='002' 
                            AND Borrow.bookNo=Book.bookNo
                        )
AND Borrow.bookNo IN (SELECT bookNo FROM Book WHERE classNo='002' 
                            AND Borrow.bookNo=Book.bookNo
                    )
AND Reader.readerNo=Borrow.readerNo 
AND Borrow.bookNo=Book.bookNo