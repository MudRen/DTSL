
inherit NPC;
#include <ansi.h>
#include <org.h>
void create()
{
       set_name("����", ({ "xie hui","xie"}) );
       set("gender", "����" );
       set("age", 40);
	   set("title","�����й�");
       set("long",
               "�����Ƕ��𱤵ı�������˵�����书��ѷɫ��[�쵶]��ȱ��\n");
       set("combat_exp", 700500);
       set("attitude", "peaceful");
	   set("gin",1500);
	   set("max_gin",1500);
	   set("kee",1500);
	   set("max_kee",1500);
	   set("sen",1500);
	   set("max_sen",1500);
	   set("max_force",2000);
	   set("force",2000);
	   set_skill("unarmed",160);
	   set_skill("dodge",160);
	   set_skill("parry",160);
           set_skill("force",160);
           set("shili",([
           "name":"duzun_b",
           "leader":"duzun_b",
           ]));
       set("shili_id","xiehui");
       setup();
 carry_object(__DIR__"obj/cloth")->wear();
 

}
int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("���Ƕ��𱤿ɲ�Ҫ�������ɵ��ˣ�\n");
	if(!ob->query("shili/leader"))
	 return notify_fail("���Ѿ����Ǳ����ˣ�����˵û�õģ�\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("��������������𱤳��۴��У�\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N��$nЦ����ϣ��$n�ܺúøɣ����Ƕ��𱤶��������أ�\n",ob,me);
	tell_object(me,HIW"\n��ȥ���������񴦴� "HIG"join"HIW" �����������ˣ�\n\n"NOR);
	
	return 1;
}

int accept_gage(object me)
{
   this_object()->fight_ob(me);
   me->fight_ob(this_object());
   return 1;
}