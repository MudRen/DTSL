


inherit __DIR__"target.c";



int chat()
{
   if(!this_object()->is_fighting())
     return ::chat();
   
   if(query("difficult")>random(100)){
      switch(random(3)){
      	case 0:
      	    command("perform dujie");
      	    break;
      	case 1:
      	    command("perform sanhua");
      	    break;
      	case 2:
      	    command("perform baihua");
      	    }
        }
    ::chat();
}






