
inherit NPC;

string *name=({
"��","tian",
"��","gang",
"��","meng",
"׳","zhuang",
"ǿ","qiang",
"��","dao"
});

void create()
{
   int i;
   
   i=random(sizeof(name));
   if(i%2!=0)
   i--;
   
   set_name("����"+name[i],({ "yuwen "+name[i+1],"yuwen",name[i+1]}) );
   set("gender", "����" );
   set("long", "�������ķ��ĵ��ӡ�\n");
       
   set("combat_exp",500000);
   set_skill("dodge",140);
   set_skill("parry",140);
   set_skill("force",140);
   set("max_force",1000);
   set("force",1000);
   setup();
   
}

void die()
{
	object ob;
	
	ob=query_temp("last_damage_from");
	if(!ob||
	   query("target_id")!=ob->query("id")
	  )
	return ::die();
	command("haha");
	command("say ������˱��Ѿ����˻ٵ��ˣ�˭Ҳ�ò����ˣ�");
	ob->set_temp("bai_shanwanjing/ok",1);
	ob->delete_temp("bai_shanwanjing/action2");
	ob->delete_temp("bai_shanwanjing/action1");
	
	return ::die();
}

int set_status(object ob)
{
  set("target_id",ob->query("id"));
  set("last",time());
  return 1;
}

int clear()
{
  if(time()-query("last")<300)
  return 0;
  if(!query("no_msg")){
  message_vision("$N���ҿ��˿��������������ˡ�\n",this_object());
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


