<?php
$con = mysql_connect("localhost","root","qwer1234");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }

mysql_select_db("SportDB", $con);

$i = 1;
$str = "athletes_name";
$temp = $str.$i;
$a = "athletes_name";
$b = "class_name";
$c = "age";
$d = "sports_name";
$e = "athletes_sex";
while (!empty($_POST[$temp])) {
    $athletes_name = mysql_real_escape_string($_POST[$a.$i]);
    $athletes_sex = mysql_real_escape_string($_POST[$e.$i]);
    $class_id = (int)$_POST[$b.$i];
    $athletes_age = (int)$_POST[$c.$i];
    $sports_name = mysql_real_escape_string($_POST[$d.$i]);
    $i++;
    $temp = $str.$i;

    //判断人数是否满
    $sql = "SELECT COUNT(Sports.sports_id) as Num, num_athletes
    FROM Score, Sports
    WHERE Score.sports_id = Sports.sports_id
    AND sports_name LIKE '$sports_name'
    GROUP BY Sports.sports_id";
    $result = mysql_query($sql);
    $row = mysql_fetch_array($result);
    //若小于 则可以插入数据
    if ($row[Num] < $row[num_athletes] || empty($row)) {
        $result = mysql_query("SELECT * FROM Athletes WHERE athletes_name LIKE '$athletes_name'");
        if($result === FALSE) { 
            die(mysql_error()); 
        }
        //如果此人没有在Athlete，则添加到Athlete
        if (!mysql_fetch_array($result))
        {
            $sql = "INSERT INTO Athletes (athletes_name, athletes_sex, athletes_age, class_id)
            VALUES
            ('$athletes_name', '$athletes_sex', $athletes_age, $class_id)";

            if (!mysql_query($sql, $con)) {
                die('Error: ' . mysql_error());
            }
        }

        $result = mysql_query("SELECT * FROM Athletes WHERE athletes_name LIKE '$athletes_name'");
        $result_sport = mysql_query("SELECT * FROM Sports WHERE sports_name LIKE '$sports_name'");
        if ($result === FALSE || $result_sport === FALSE) { 
            die(mysql_error()); 
        }
        $row = mysql_fetch_array($result);
        $row_sport = mysql_fetch_array($result_sport);
        //插入Score表
        $sports_id = (int)$row_sport['sports_id'];
        $athletes_id = (int)$row['athletes_id'];
        $sql = "INSERT INTO Score (sports_id, athletes_id)
        VALUES
        ($sports_id, $athletes_id)";
        if (!mysql_query($sql, $con)) {
            die('Error: ' . mysql_error());
        }
    }
}
mysql_close($con);

echo "<script language='javascript' type='text/javascript'>";
echo "alert('Add successful');";
echo "</script>";

$URL="register.html";
echo "<script>location.href='$URL'</script>";

?>