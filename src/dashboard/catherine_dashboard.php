<!DOCTYPE html>
<html>
<head>
	<meta http-equiv="refresh" content="5" charset="utf-8">
	<link rel="stylesheet" type="text/css" href="cathy_close_contactstyle.css" media="screen">
	<title>Recede database</title>
</head>
<body>
		<button class="back"><a href="dashboardver2.php">Back</a></button>	
		<h1>CATHERINE CLOSE CONTACT</h1>

<?php
include 'search2.php';
$servername = "localhost";
$username = "root";
$password = "secret";
$dbname  = "esp32";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error){
	die("Connection failed: " .$conn->connect_error);
}
$sql = "SELECT id, value, created FROM catherine_close_contact ORDER BY id DESC";

// echo '<table cellspacing="3" cellpadding="3">
// 		<tr>
// 			<th>ID</th>
// 			<th>VALUE</th>
// 			<th>CREATED</th>
// 		</tr>';

if ($result = $conn->query($sql)){
	while($row = $result->fetch_assoc()){
		$row_id = $row["id"];
		$row_value = $row["value"];
		$row_created = $row["created"];
		

		// echo'<tr>
		// 	<td>' . $row_id . '</td>
		// 	<td>' . $row_value . '</td>
		// 	<td>' . $row_created . '</td>
		// </tr>';

	}
	$result->free();
}
$conn->close();
?>
</body>
</html>
