


inherit __DIR__"target.c";



int chat()
{
   string *pfm;
   
   pfm=query("can_perform");
   
   if(arrayp(pfm)&&is_fighting()&&random(100)>query("pfm_rate")){
     set("apply_points",100);
     command("perform "+pfm[random(sizeof(pfm))]);
     return 1;
   }
   
   return ::chat();
}






