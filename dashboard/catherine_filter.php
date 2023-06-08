<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" href="search.css" media="screen">
	<title>Search</title>
</head>
<body>
	<div class="search">
		<form method="GET">
			<input type="text" <?php if(isset($_GET['search'])){echo $_GET['search']; } ?>placeholder="YYYY-MM-DD" name="search">
			<button class="btnsearch" type="submit">Search</button> 
		</form>
	<div class="search">
		<table class="table">
			 <thead>
             <tr>
                     <th>ID</th>
                     <th>Value</th>
                     <th>Created</th>
             </tr>
             </thead> 
                    <tbody>
                                <?php 
                                    $con = mysqli_connect("localhost","root","secret","esp32");

                                    if(isset($_GET['search']))
                                    {
                                        $filtervalues = $_GET['search'];
                                        $query = "SELECT * FROM catherine_close_contact WHERE CONCAT(id,value,created) LIKE '%$filtervalues%' ";
                                        $query_run = mysqli_query($con, $query);

                                        if(mysqli_num_rows($query_run) > 0)
                                        {
                                            foreach($query_run as $items)
                                            {
                                                ?>
                                                <tr>
                                                    <td><?= $items['ID']; ?></td>
                                                    <td><?= $items['value']; ?></td>
                                                    <td><?= $items['Created']; ?></td>
                                                </tr>
                                                <?php
                                            }
                                        }
                                        else
                                        {
                                            ?>
                                                <tr>
                                                    <td colspan="4">No Record Found</td>
                                                </tr>
                                            <?php
                                        }
                                    }
                                ?>
                            </tbody>
		</table>
	</div>
</body>
</html>
