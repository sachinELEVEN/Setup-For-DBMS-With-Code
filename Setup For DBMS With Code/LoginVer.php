<?php
// establishing a connection to the server
//$AgeCon =  5 //$_GET["Age"]
    
$username = 'root';
$password = '';
$db = 'Nsit';
  $nnn =  'Akhil';
    $quer = $_GET["query"];
    $ColName1 = $_GET["col1"];
    $ColName2 = $_GET["col2"];
  
  
    
//    $querryString = 'SELECT * FROM `Students` WHERE Name = "Sachin" ';
    $querryString  =  $quer;//'SELECT*FROM`Students`';
$conn = new mysqli ('localhost',$username, $password, $db) or die("unable to connect");

 
   // echo   $quer;
// printing column name above the data
   // header('Content-type: text/plain');
  //  echo 'ID'.' '.'Name'.' '.'Age';
//  echo $agee
// sql query to fetch all the data
  //  echo "<br>";
$query = $querryString;
    //  echo 'Query to be Executed';
    
    
    $result = mysqli_query($conn,$query);
   // echo $result
    
   //Header for below data
    
//     echo "   |  ";echo "ID";echo "  |   ";echo "cust_name";echo "  |   ";echo "Name";
//    echo"\n";
//    echo "   | ";echo "____" ;echo " |  ";echo "_____"; echo " |  ";echo "_____";
//     echo"\n";
    // echo"\n";
    
    echo"\r";
    
    if ($result){
       while ($row = $result->fetch_assoc()) {
       //  echo "<br>";
            echo "   |  ";
           echo $row[$ColName1];
           //  echo "\r";
         echo "   |  ";
           echo $row[$ColName2];
        //   echo "\n";
          
           //For new line
           echo "\r";
            echo "\r";
           echo "You are now logged in";
       }
    }else{
        echo " You are not authorised to login";
    }
// mysql_query will execute the query to fetch data
// echo    mysqli_query($conn,$query)
//    if ($is_query_run = mysqli_query($conn,$query))
//{
//     echo 'Query Executed';
//    // loop will iterate until all data is fetched
//    while ($query_executed = mysqli_fetch_assoc ($is_query_run))
//    {
//        // these four line is for four column
//        echo $query_executed['id'].' ';
//        echo $query_executed['Name'].' ';
//        echo $query_executed['Age'].';';
//
//    }
//}
//else
//{
//    echo "Error in execution";
    echo"\n\n\n";
    echo "Done1";
//}
?>
