<?php
include ('connectDB.php');  
$location_id = $_GET['l_id'];
$timepast = $_GET['lt']; 

$query = "INSERT INTO leavingTime (`id`, `location_id`, `time_past`) VALUES (NULL," . $location_id . "," . $timepast . ");";
if (!($result = $mysqli->query($query)))
    showerror($mysqli->errno,$mysqli->error);

?>