
inherit NPC;

void create()
{
   set_name("����",({ "shi wei","shi","wei" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "���������丮������,����������İ�ȫ��\n");
       
   set("combat_exp",500000);
   set("str", 26);
   set("per", 22);
   set("shili","wang");
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/gangjian")->wield();
  
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	if(!ob||!present(ob,environment())) return; 
	if((int)ob->query("beipan",1)>=3)
		call_out("kill_pantu",1,ob,ob2);
	return;
}

void kill_pantu(object ob,object ob2)
{
	if(!ob) return;
	message_vision("$N��$n��Ц��:�������ֶ����������ͽ����������!\n",ob2,ob);
    ob2->kill_ob(ob);
	remove_call_out("kill_pantu");
	return;
}
