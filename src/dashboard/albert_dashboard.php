<!DOCTYPE html>
<html>
<head>
	<meta http-equiv="refresh" content="5" charset="utf-8">
	<link rel="stylesheet" type="text/css" href="albert_close_contactstyle.css" media="screen">
	<title>Recede database</title>
</head>
<body>
		<button class="back" id="myInput" onkeyup="myFunction()"><a href="dashboardver2.php">Back</a></button>	
		<h1>ALBERT CLOSE CONTACT</h1>

<?php
include 'search.php';
$servername = "localhost";
$username = "root";
$password = "secret";
$dbname  = "esp32";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error){
	die("Connection failed: " .$conn->connect_error);
}
$sql = "SELECT id, value, created FROM albert_close_contact ";

// echo '<table cellspacing="3" cellpadding="3">';

			// 		<th>ID</th>
			// <th>VALUE</th>
			// <th>CREATED</th>
if ($result = $conn->query($sql)){
	while($row = $result->fetch_assoc()){
		$row_id = $row["id"];
		$row_value = $row["value"];
		$row_created = $row["created"];
		

		// echo '<tr>
		// 	<th>' . $row_id . ' </th>
		// 	<th>' . $row_value . '</th>
		// 	<th>' . $row_created . '</th><br>
		// </tr>';

	}
	$result->free();
}
$conn->close();
?>


</body>
</html>
