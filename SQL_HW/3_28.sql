CREATE VIEW m_Reader
AS 
    SELECT readerNo, readerName, datediff(year,convert(datetime,(substring(identitycard,7,8))),getdate()), workUnit
    FROM Reader x
    WHERE EXISTS
        (SELECT * 
            FROM Reader
            WHERE x.readerNo = Reader.readerNo
            AND datediff(year,convert(datetime,(substring(identitycard,7,8))) BETWEEN 25 AND 35
        )