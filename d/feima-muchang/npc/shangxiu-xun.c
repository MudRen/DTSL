inherit NPC;
#include <ansi.h>
#include <org.h>

int do_action1();

void create()
{
   set_name("���㫑",({ "shang xiuxun","shang"}) );
   set("gender", "Ů��" );
		
   set("age", 25);
   set("long", "�����Ƿ���������̬��ǧ���ں�Ư����\n"+
               "�㷢������С�ٲ�����к���������Ƶ���\n"+
               "�紦���������Ѱ�������Ƕ�����������\n"+
               "�⣬Ũ�ܵ��۽�ë��Ϊ����˫��������\n"+
               "���������ķ�Ŀ�������������ظС�\n");
       
   set("combat_exp",600000);
   set("str", 24);
   set("per", 27);
   set_skill("unarmed",170);
   set_skill("dodge",170);
   set_skill("parry",170);
   set_skill("sword",170);
   set_skill("qingxuan-jianfa",170);

   set_skill("babu-ganchan",170);
  
   set("shili",([
       "name":"feima_b",
       "leader":"feima_b",
       ]));
   set("shili_id","feima");
   
   set("inquiry",([
       "��������":(:do_action1:),
      ]));
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}


int accept_gage(object me)
{
   this_object()->fight_ob(me);
   me->fight_ob(this_object());
   return 1;
}

int accept_object(object me,object obj)
{
    
    if(!obj->id("baihuajian_quest_obj"))
     return notify_fail("�ҿɲ����Ҫ���˵Ķ�����\n");
    
    me->set_temp("bai_huajian/step1",1);
    command("say лл����Ҵ�����ô�óԵĶ�����");
    return 1;
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   command("say ���ɾ��������ɺͻ����ɣ�����һ����������Ϊ�ף�\n"+
           "�ǲ����򻨼䲻�����ֻ�ǻ�����ÿ��ֻ��һ�ˡ�����\n"+
           "����ر����أ���ħ�ŵ��ˣ��಻֪��˭�ǻ����ɵĴ��ˡ�\n");
   if(ob->query_temp("bai_huajian/step1")){
       ob->delete_temp("bai_huajian/step1");
       ob->set_temp("bai_huajian/step2",1);
   }
   return 1;
}

int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("���Ƿ��������ɲ�Ҫ�������ɵ��ˣ�\n");
	if(!ORG_D->is_leader("feima"))
	 return notify_fail("���Ѿ����ǳ����ˣ�����˵û�õģ�\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("���������������Ч�ҷ���������\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N��$nЦ����ϣ��$n�ܺúøɣ�ʹ���Ƿ�����������ǿ��\n",ob,me);
	tell_object(me,HIW"\n��ȥ���������񴦴� "HIG"join"HIW" �����������ˣ�\n\n"NOR);
	
	return 1;
}