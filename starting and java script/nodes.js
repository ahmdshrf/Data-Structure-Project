function create_ellipse( a ,  b , len , ele){
    var a_sqr = a * a ; var b_sqr = b*b ; var count = ele;
    var  theta = (360/len)* Math.PI / 180 ;
    for (i = 0 ; i < len/2 ; i++){
        for (k = -1 ; k < 2 ; k++){
            if (k == 0){
                continue;
            }
            var new_node = document.createElement("p");
            new_node.setAttribute("class","node");
            new_node.setAttribute("id","node_"+count);
            var append_to = document.getElementById("center");
            append_to.appendChild(new_node);
            var left_offset = Math.sqrt((b_sqr*a_sqr)/(a_sqr+b_sqr*Math.pow(Math.tan(theta*i),2)));
            new_node.style.left = "calc(-50% + " + k*left_offset+"px)";
            var top_offset = left_offset * Math.tan(theta*i);
            new_node.style.top = "calc(-50% + " + k*top_offset +"px)";
            new_node.innerHTML = count ; 
            new_node.setAttribute("onclick","say_my_name("+count+")");
            count++ ; 
            }
        }
    //even numbers for a regular ellipse 
}
function say_my_name(val){
    document.cookie="Value="+val ;
}
function create_nodes(size){
    var arr = [28,24,20,16,12,8,4,2]; 
    var ele = 0 ; var size_ = size ; 
    for (j = 0 ; j < 10 ; j++){
        if (size_/arr[j] >= 1){
        var  len  = arr[j] ; var a = (43*arr[j]/4) ; var b = a*1.5 ; 
        create_ellipse(a,b,len,ele);
        ele = ele + arr[j] ;
            size_ -= arr[j]; 
        }
        else{
            continue;
        }
    }
    if (size_ == 1){
        var new_node = document.createElement("p");
        new_node.setAttribute("class","node");
        new_node.setAttribute("id","node_"+ele);
        new_node.innerHTML = ele; 
        var append_to = document.getElementById("center");
        new_node.setAttribute("onclick","say_my_name("+ele+")");
        append_to.appendChild(new_node);
        new_node.style.left = "-50%";
        new_node.style.top="-50%";
    }
}