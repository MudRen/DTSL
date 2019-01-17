
inherit NPC;
inherit F_SAVE;
#include <ansi.h>
string query_save_file()
{

	string id2;

	if( !stringp(id2 = query("npc_id")) ) return 0;
	return DATA_DIR + "npc/boss/" + id2;
}

void create()
{
   set_name("������",({ "li shimin","li","shimin" }) );
        set("gender", "����" );
        set("age", 25);
   set("long", "����ǳ�����Ķ�����������\n");
   set("shili","li");
   set("combat_exp", 700000);
   set("str", 28);
   set("per", 26);
   set("attitude", "peaceful");
   set_skill("unarmed",170);
   set_skill("parry",170);
   set_skill("dodge",170);
   set_skill("force",170);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   set("shili",([
      "name": "lifa_b",
      "leader": "lifa_b",
      "deadtimes":0,
      ]));
   set("npc_id","lishimin");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  restore();
}

int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("������ɲ�Ҫ�������ɵ��ˣ�\n");
	if(!ob->query("shili/leader"))
	 return notify_fail("���Ѿ����Ǳ����ˣ�����˵û�õģ�\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("�������������ض�ͳһ��ԭ��\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N��$nЦ����ϣ��$n�ܺúøɣ����հ��������ͳһ���£�\n",ob,me);
	tell_object(me,"��ȥ���������񴦴� join �����������ˣ�\n");
	CHANNEL_D->do_channel(this_object(), "rumor",
	sprintf("%s�����˳��������\n",me->name()));
	return 1;
}
	

