

void die()
{
   object ob;
   
   
   ob=query_temp("last_damage_from");
   if(!ob) return ::die();
   if(ob->query("id")!=query("target_id"))
   return ::die();
   
   JOBSYS_D->give_reward_questjob(ob,this_object());
   
   return ::die();
}

int clear()
{
  if(time()-query("last")<300)
  return 0;
  if(!query("no_msg")){
  message_vision("$N�Ҵҵ����ˡ�\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void dispear()
{
   destruct(this_object());
   return;
}


int chat()
{
   
   if(clear())
   return 1;
   return ::chat();
}   