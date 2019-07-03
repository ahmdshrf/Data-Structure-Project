<?php
$file = fopen($_POST["filename"] ,"r");
if (!empty($file)){
function get($file){
    $line = fgets($file); $arr = array();
    $f = explode(' ',$line);
    for ($j = 0 ; $j < count($f) ; $j++){
        if ($f[$j] !=' ' and $f[$j] != null){
            array_push($arr,$f[$j]);
        }
    }
    $fir = $arr[0] ; $sec = $arr[1] ; 
    return array($fir,$sec);
}
$got = get($file);
$size = (int)$got[0] ;
$n = (int) $got[1] ; 
echo "
<!DOTYPE html>
<html>
<head>
<link rel='stylesheet' href='1.css' type='text/css'/>
<script src='connector.js'></script>
<script src='nodes.js'></script>
</head>
<body>
<div id='cont'>
<div id='center' class='center_'></div>
</div>
<script>
create_nodes($size);
document.cookie='Value=RUBBISH';
</script>
";
for ($i = 0 ;  $i < $n ; $i++){
    $line = fgets($file); $arr = array();
    $f = explode(' ',$line);
    for ($j = 0 ; $j < count($f) ; $j++){
        if ($f[$j] !=' ' and $f[$j] != null){
            array_push($arr,$f[$j]);
        }
    }
    $fir = $arr[0] ; $sec=$arr[1] ; $weight=$arr[2] ; 
    if ($fir == $_COOKIE["Value"]){
        echo "<script>
        document.getElementById('node_$sec').style.boxShadow='0px 0px 10px black' ; 
        </script>";
    }
    else if ($sec == $_COOKIE["Value"]){
        echo "<script>
        document.getElementById('node_$fir').style.boxShadow='0px 0px 10px black' ;
        </script>";
    }
    echo "<script>
    connect($fir,$sec);
    </script>";
}
echo "</body>
</html>" ;
}
?>