
inherit NPC;
#include <ansi.h>
#include <org.h>

void create()
{
   set_name("������",({ "han gaitian","han","gaitian" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "���Ǻ�ɳ��İ�����\n");
       
   set("combat_exp", 5000);
   set("str", 24);
    set("attitude", "friendly");
    set("shili",([
       "name":"haisha_b",
       "leader":"haisha_b",
       ]));
    set("shili_id","haisha");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("���Ǻ�ɱ��ɲ�Ҫ�������ɵ��ˣ�\n");
	if(!ob->query("shili/leader"))
	 return notify_fail("���Ѿ����ǰ����ˣ�����˵û�õģ�\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("�������������ɱ�������޵У�\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N��$nЦ����ϣ��$n�ܺúøɣ�ʹ���Ǻ�ɱ���۰Խ��ϣ�\n",ob,me);
	tell_object(me,HIW"\n��ȥ���������񴦴� "HIG"join"HIW" �����������ˣ�\n\n"NOR);
	
	return 1;
}

int accept_gage(object me)
{
   this_object()->fight_ob(me);
   me->fight_ob(this_object());
   return 1;
}