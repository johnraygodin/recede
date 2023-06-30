<?php
$servername = "localhost";
$username = "root";
$password = "secret";
$dbname = "esp32";

$value = "";

if($_SERVER["REQUEST_METHOD"] == "POST"){
	$value = $_POST["value"];

	$conn = new mysqli($servername, $username, $password, $dbname);
	
	if($conn->connect_error){
	die("Connection failed: " . $conn->connect_error);
	}
	$sql = "INSERT INTO jellie_close_contact (value) VALUES ('" . $value ."')";

	if ($conn->query($sql) == TRUE){
		echo"New record created successfully";
	}else{
		echo"Error: " . $sql . "<br>" . $conn->error;
	}
	
	$conn->close();		
}else{
echo"No data posted with HTTP POST.";
}

?>
