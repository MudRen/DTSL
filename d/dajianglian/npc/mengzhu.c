
inherit NPC;
#include <ansi.h>
#include <org.h>

void create()
{
   set_name("֣����",({ "zheng shuming","zheng"}) );
        set("gender", "Ů��" );
        set("age", 32);
   set("long", "���Ǵ�����������\n");
       
   set("combat_exp", 5000);
   set("str", 24);
    set("attitude", "friendly");
    set("shili",([
       "name":"dajiang_b",
       "leader":"dajiang_b",
       ]));
    set("shili_id","dajiang");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}
int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("���Ǵ����ɲ�Ҫ�������ɵ��ˣ�\n");
	if(!ob->query("shili/leader"))
	 return notify_fail("���Ѿ����������ˣ�����˵û�õģ�\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("����������������۰Խ��ϣ�\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N��$nЦ����ϣ��$n�ܺúøɣ�ʹ���Ǵ����۰Գ�����\n",ob,me);
	tell_object(me,HIW"\n��ȥ���������񴦴� "HIG"join"HIW" �����������ˣ�\n\n"NOR);
	
	return 1;
}

int accept_gage(object me)
{
   this_object()->fight_ob(me);
   me->fight_ob(this_object());
   return 1;
}
