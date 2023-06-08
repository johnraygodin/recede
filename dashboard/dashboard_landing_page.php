<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Dashboard</title>
    <link rel="stylesheet" type="text/css" href="dashboardver2style.css" media="screen">
  </head>
  <body>
    <h2>RECEDE MONITORING SYSTEM</h2>
    <input type="text" id="myInput" class="search" onkeyup="myFunction()" placeholder="Search participants">

    
    <div class="container">
        
        <table id="myTable" cellspacing="1" cellpadding="1">
            <tr class="header">
                 <th class="databases">DEVICE USERS</th>
                 
            </tr>
            <tr>
                <td><a class="hovers" href="cathy_close_contact.php">Catherine G. Duero</a></td>
            </tr>
            <tr>
                <td><a class="hovers" href="jhellay_close_contact.php">Jellie Marie J. Jover</a></td>
            </tr>
            <tr>
                <td><a class="hovers" href="albert_close_contact.php">Albert S. Parreño</a></td>
            </tr>
            <!-- <tr>
                <td>Jason P. Esperela</td>
            </tr>
            <tr>
                <td>John Ray T. Godin</td>
            </tr> -->
        </table>

    </div>

    <script>
        function myFunction(){
        var input, filter, table, tr, td, i, txtValue;
        input = document.getElementById("myInput");
        filter = input.value.toUpperCase();
        table = document.getElementById("myTable");
        tr = table.getElementsByTagName("tr");

        for (i = 0; i < tr.length; i++){

            td = tr[i].getElementsByTagName("td")[0];

            if (td){
                txtValue = td.textContent || td.innerText;
                if (txtValue.toUpperCase(). indexOf(filter) > -1){
                    tr[i].style.display = "";
                }
                else{
                    tr[i].style.display = "none";
                }
            }
            
        }
        }
    </script>
  </body>
</html>
