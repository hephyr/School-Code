SELECT Reader.readerNo, readerName, substring(identitycard, 7, 8) as birthday
FROM Book, Reader, Borrow
WHERE Reader.readerNo NOT IN (SELECT Reader.readerNo
                                FROM Book, Reader, Borrow, BookClass
                                WHERE className = '经济管理'
                                AND Book.bookNo = Borrow.bookNo
                                AND Book.classNo = BookClass.classNo
                                AND Reader.readerNo = Borrow.readerNo
                            )
AND Book.bookNo = Borrow.bookNo
AND Reader.readerNo = Borrow.readerNo
