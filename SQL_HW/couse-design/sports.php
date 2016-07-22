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

$sql="SELECT sports_id, sports_name, num_athletes, referee_name
FROM Sports, Referee
WHERE Sports.referee_id = Referee.referee_id;";

$result = mysql_query($sql);
echo "<table class='table table-bordered'>
<tr>
<th>项目名称</th>
<th>已报名人数</th>
<th>最大参加人数</th>
<th>裁判员</th>
</tr>";
while($row = mysql_fetch_array($result))
{   
    $temp = (int)$row[sports_id];
    $sql2="SELECT sports_id, COUNT(sports_id) AS Num
    FROM Score
    WHERE sports_id = $temp
    GROUP BY sports_id;";
    $result2 = mysql_query($sql2);
    $row2 = mysql_fetch_array($result2);

    echo "<tr>";
    echo "<td>" . $row[sports_name] . "</td>";
    if (empty($row2)) {
        echo "<td>" . 0 . "</td>";
    } else {
        echo "<td>" . $row2[Num] . "</td>";
    }
    echo "<td>" . $row[num_athletes] . "</td>";
    echo "<td>" . $row[referee_name] . "</td>";
    echo "</tr>";
}
echo "</table>";

mysql_close($con);
?>
</body>
</html>