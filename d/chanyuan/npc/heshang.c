
inherit NPC;

void create()
{
   set_name("����",({ "he shang","bonze","he","shang"}));
        set("gender", "����" );
        set("age", 22);
   set("long", "���Ǿ�����Ժ�ĺ��С������������书Ҳ�ǲ��ס�\n");
   set("class","bonze"); 
   set("combat_exp", 400000);
   set("str", 28);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("dodge",80);
   set_skill("parry",90);
   set_skill("staff",90);
   
   create_family("������Ժ",7,"ɮ��");
   setup();
   carry_object(__DIR__"obj/sengyi")->wear();
   carry_object(__DIR__"obj/staff")->wield();
  
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())) return;
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())) return;
	switch(random(2))
	{
	case 0: message_vision("$N�����е��������ӷ�!\n",ob2);break;
	case 1: message_vision("$N��$n���������Ե�ˡ�\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
