
inherit NPC;

void create()
{
   set_name("����",({ "bu pen","bu","pen"}));
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǿ�����Ժ���Ĵ󻤷����֮һ��\n");
   set("class","bonze");
   set("combat_exp", 400000);
   set("str", 28);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("dodge",80);
   set_skill("parry",90);
   set_skill("staff",90);
   set_skill("blade",150);
   set_skill("force",150);
   set_skill("chanzong-fofa",150);
   // set_skill("jinguang-daofa",150);
   // set_skill("wuxiang-zhangfa",90);
   set("staff",({"wuxiang-zhangfa"}));
   set_skill("liuyun",150);
   set("dodge",({"liuyun"}));
    create_family("������Ժ",4,"����");
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
	if(present("heshi bi",ob))
		call_out("kill_thief",1,ob,ob2);
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
void kill_thief(object ob,object ob2)
{
	if(!ob||!present(ob,environment())) return;
	message_vision("$N��$n����˵����ʩ��Ϊ��Ҫ����������ˮ��!\n",ob2,ob);
	ob2->kill_ob(ob);
	remove_call_out("kill_thief");
}
