
inherit NPC;

void create()
{
   set_name("�ٱ�",({ "bing" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "���������ϷʵĹٱ��������������������ˡ�\n");
       
   set("combat_exp",200000);
   set("str", 26);
   set("per", 22);
   set("guard","hefei");
   set("shili","luoyang");
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/junfu")->wear();
   carry_object(__DIR__"obj/gangjian")->wield();
  
}

void init()
{
	object *ob,here,me;int i;
	me=this_object();
	here=environment(me);
	ob=all_inventory(here);
	for(i=0;i<sizeof(ob);i++)
	{
	
     if(ob[i]->query("killer")==me->query("guard"))
		call_out("kill_killer",1,ob[i],me);
	 else if((int)ob[i]->query("beipan",1)>=3)
		call_out("kill_pantu",1,ob[i],me);
	}
	return;
}

void kill_pantu(object ob,object ob2)
{
	if(!ob||!ob2) {remove_call_out("kill_pantu");return;}
	message_vision("$N��$n��Ц��:�������ֶ����������ͽ����������!\n",ob2,ob);
    ob2->kill_ob(ob);
	remove_call_out("kill_pantu");
	return;
}
void kill_killer(object ob,object ob2)
{
	if(!ob||!ob2) {remove_call_out("kill_killer");return;}
	ob2->kill_ob(ob);
	remove_call_out("kill_killer");return;
}