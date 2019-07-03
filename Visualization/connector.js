function connect(a_id,b_id){
        var a = document.getElementById("node_"+a_id).getBoundingClientRect();
        var b = document.getElementById("node_"+b_id).getBoundingClientRect();
        var rotate = Math.atan((a.top-b.top)/(a.left-b.left))*180/Math.PI;
        var neat ; 
        if (a.top > b.top){
            if (a.left >= b.left){
                 neat = b ; 
            }
            else{
                 neat = a ; 
            }
        }
        else{
            if (a.left >= b.left){
                neat = b ; 
            }
            else{
                neat =  a;
            }
        }
    var new_line =  document.createElement("div") ; 
    var append_to = document.getElementById("cont") ; 
    append_to.appendChild(new_line) ;
    new_line.setAttribute("id",a_id+"_"+b_id);
    new_line.setAttribute("class","line");
    new_line.style.top = neat.top+6-2+scrollY  + "px" ;
    new_line.style.left = neat.left+6-2+scrollX + "px" ;
    new_line.style.transform="rotate("+rotate+"deg"+")";
    var len = Math.pow(a.left-b.left,2) + Math.pow(a.top-b.top,2) ;
    len = Math.sqrt(len) ; 
    new_line.style.width = len + "px" ; 
}
//lines created will have 1_2
