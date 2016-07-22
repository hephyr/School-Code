<?php
$con = mysql_connect("localhost","root","qwer1234");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }

mysql_select_db("SportDB", $con);

$sql="SELECT athletes_name, class_name, score, Athletes.athletes_id
FROM Score, Class, Athletes
WHERE Athletes.athletes_id IN (
    SELECT athletes_id FROM Score WHERE sports_id IN (
        SELECT sports_id FROM Sports WHERE sports_name LIKE '$_POST[sports_name]'))
AND Score.athletes_id=Athletes.athletes_id
AND Athletes.class_id=Class.class_id
AND sports_id IN (SELECT sports_id FROM Sports WHERE sports_name LIKE '$_POST[sports_name]');";

$result = mysql_query($sql);

if($result === FALSE) {
    echo "err";
    die(mysql_error()); 
}

$i = 1;
$str = "setscore";
$temp = $str.$i;
while ($row = mysql_fetch_array($result)) {
    $update_sql="UPDATE Score SET score = $_POST[$temp]
    WHERE athletes_id = $row[athletes_id]
    AND sports_id IN (SELECT sports_id FROM Sports WHERE sports_name LIKE '$_POST[sports_name]')";
    mysql_query($update_sql);
    $i++;
    $temp=$str.$i;
}
mysql_close($con);

echo "<script language='javascript' type='text/javascript'>";
echo "alert('Add successful');";
echo "</script>";

$URL="score.html";
echo "<script>location.href='$URL'</script>";
?>