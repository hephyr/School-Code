<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Ristorante Con Fusion</title>
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <link href="css/bootstrap-theme.min.css" rel="stylesheet">
    <link href="css/font-awesome.min.css" rel="stylesheet">
    <link href="css/bootstrap-social.css" rel="stylesheet">
    <link href="css/mystyles.css" rel="stylesheet">
</head>
<body>
<?php
$q=$_GET["q"];

$con = mysql_connect('localhost', 'root', 'qwer1234');
if (!$con)
 {
 die('Could not connect: ' . mysql_error());
 }

mysql_select_db("SportDB", $con);

$sql="SELECT class_name, SUM(score) AS final_score
FROM Score, Class, Athletes
WHERE Score.athletes_id=Athletes.athletes_id
AND Athletes.class_id=Class.class_id
GROUP BY class_name
ORDER BY final_score DESC";

$result = mysql_query($sql);

echo "<table class='table table-bordered'>
<tr>
<th>名次</th>
<th>班级</th>
<th>成绩</th>
</tr>";
$i = 1;
while($row = mysql_fetch_array($result))
 {
 echo "<tr>";
 echo "<td>" . $i . "</td>";
 $i++;
 echo "<td>" . $row[class_name] . "</td>";
    if (!$row[final_score]) {
        echo "<td>" . 0 . "</td>";
    } else {
        echo "<td>" . $row[final_score] . "</td>";
    }
 echo "</tr>";          
 }
echo "</table>";

mysql_close($con);
?>
</body>
</html>