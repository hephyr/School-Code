CREATE VIEW qinghua_public
AS
    SELECT Book.*
    FROM Book, BookClass
    WHERE publishingName = '清华大学出版社'
    AND year(publishingDate) BETWEEN 2008 AND 2009
    AND className = '计算机'
    AND Book.classNo = BookClass.classNo