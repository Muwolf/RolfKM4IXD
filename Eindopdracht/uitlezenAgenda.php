<?php
include ('connectDB.php');  
$timeleft = 604800; 
$too_late = 0;
$location_id = 0; 

$query = "SELECT UNIX_TIMESTAMP(MIN( c.date )) - UNIX_TIMESTAMP(NOW( )) - l.travel_time AS timeleft, ROUND(AVG(lt.time_past)) AS too_late, l.id AS location_id
FROM calender c
LEFT JOIN location l ON ( c.location_id = l.id ) 
LEFT JOIN leavingTime lt ON ( lt.location_id = l.id ) 
WHERE UNIX_TIMESTAMP(c.date) > UNIX_TIMESTAMP(NOW( )) - 599
GROUP BY c.id
";

if (!($result = $mysqli->query($query)))
    showerror($mysqli->errno,$mysqli->error);
while ($row = $result->fetch_assoc()){
    if ($row['timeleft'] <= $timeleft) {
        $timeleft = $row['timeleft']; 
        $too_late = $row['too_late'];
        $location_id = $row['location_id'];
    }
}


$timeleftNew = $timeleft + map($too_late, 600, 1800, $timeleft, $timeleft/2);
if ($timeleftNew < $timeleft/2){
    $timeleftNew = $timeleft/2;
} else if ($timeleftNew > $timeleft){
    $timeleftNew = $timeleft; 
}

$timeleft = $timeleftNew; 

$days = roundoff($timeleft/86400);
$hours = roundoff(($timeleft % 86400) / 3600);
$minutes = roundoff((($timeleft % 86400) % 3600) / 60);
$seconds = ((($timeleft % 86400) %3600) % 60);

echo "day: " . $days . "<br>hrs: " . $hours . "<br>min: " . $minutes . "<br>sec: " . $seconds . "<br>loc: " . $location_id . "<br>";

function map($value, $in_min, $in_max, $out_min, $out_max) {
    if ($in_min == $in_max) return null; 
    return $out_min - round(($value - $in_min) * ($out_max - $out_min) / ($in_max - $in_min) + $out_min);
}

function roundoff($value){
    if ($value > 0){
        return floor($value);
    } else { 
        return ceil($value); 
    }
}

?>