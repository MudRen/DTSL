
inherit NPC;
#include <ansi.h>
#include <org.h>

int do_action1();

void create()
{
   set_name("������",({ "li shimin","li","shimin" }) );
   set("gender", "����" );
   set("age", 25);
   set("long", "����ǳ�����Ķ�����������\n");
   set("combat_exp", 100000);
   set("str", 28);
   set("per", 26);
   set("attitude", "peaceful");
   set_skill("parry",100);
   set_skill("unarmed",100);
   set_skill("dodge",100);
   set_skill("force",100);
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
   set("shili_id","lishimin");
   set("inquiry",([
    "������":(:do_action1:),
   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("������߸��ɲ�Ҫ�������ɵ��ˣ�\n");
	if(!ob->query("shili/leader"))
	 return notify_fail("���Ѿ����������ˣ�����˵û�õģ�\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("�������������ض�ͳһ��ԭ��\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N��$nЦ����ϣ��$n�ܺúøɣ����հ��������ͳһ���£�\n",ob,me);
	tell_object(me,HIW"\n��ȥ���������񴦴� "HIG"join"HIW" �����������ˣ�\n\n"NOR);
	
	return 1;
}
	
int accept_gage(object me)
{
   this_object()->fight_ob(me);
   me->fight_ob(this_object());
   return 1;
}

void kill_ob(object ob)
{
   object guard;
   
   if(!ob->query_temp("help_ssbp_action1"))
   return ::kill_ob(ob);
   
   if(present("ning daoqi",environment(ob)))
   guard=present("ning daoqi",environment(ob));
   else
   guard=new("/d/quest/ssbp/ningdaoqi");
   guard->set("target_id",ob->query("id"));
   guard->move(environment(ob));
   remove_killer(ob);
   ob->remove_killer(this_object());
   guard->do_command("say ��ɱ��������ɱ���Ϸ�ɣ�");
   guard->kill_ob(ob);
   ob->kill_ob(guard);
   remove_call_out("check_fight");
   call_out("check_fight",1,guard,ob,1);
   return;
}

void check_fight(object guard,object ob,int i)
{
   object *objs,target;
   
   if(!guard) return;
   if(!ob) return;
   
   if(!guard->is_fighting(ob)) return;
   
   i++;
   
   if(i>=30){
     guard->remove_killer(ob);
     ob->remove_killer(guard);
     
     ob->set("dtsl_quest_ssbp_help_ok",1);
     ob->delete_temp("help_ssbp_action1");
     guard->do_command("say ������Ĺ��򻹲����Ϸ��������㲻����");
     
     if(random(ob->query_quest_kar()+ob->query_kar())<28){
      destruct(guard);
      return;
     }
     objs=all_inventory(environment(ob));
     objs=filter_array(objs,(:userp:));
     objs=filter_array(objs,(:$1!=$2:),ob);
     objs=filter_array(objs,(:!$1->query("dtsl_quest_ssbp_ok"):));
     objs=filter_array(objs,(:!$1->query("perform_quest/ssbp_fail"):));
     if(sizeof(objs)){
       target=objs[random(sizeof(objs))];
       if(target->query("age")<18&&
       	  target->query("combat_exp")>=500000&&
       	  target->query("int")>=25&&
          random(target->query_kar())<29){
       	message_vision("$N����һƬ��ã���ƺ������������޷�׽�������ɵ�̾�˿�����\n",target);	
       	target->add("perform_quest/ssbp_fail_times",1);
       	if(target->query("perform_quest/ssbp_fail_times")>=2){
       		target->set("perform_quest/ssbp_fail",1);
       		tell_object(target,"\n��ҡ��ҡͷ�������������޷��������־����ˣ�\n");
       	}
       	guard->do_command("say ƾ���������ɱ����������ģ�ϣ�����Ժ����Ϊ֮��");
       	guard->do_command("bye");
       	destruct(guard);
       	return;
       }
       message_vision("$N���Ա߿������˵ı��䣬�ƺ���������\n",target);
       target->do_command("smirk");
       target->set_skill("sanshou-strike",10);
       target->set("dtsl_quest_ssbp_ok",1);       
       guard->do_command("say ƾ���������ɱ����������ģ�ϣ�����Ժ����Ϊ֮��");
       guard->do_command("bye");
       destruct(guard);
     }
     else{
     	guard->do_command("say ƾ���������ɱ����������ģ�ϣ�����Ժ����Ϊ֮��");
      guard->do_command("bye");
      destruct(guard);
     }	
     return;
   }
   
   call_out("check_fight",1,guard,ob,i);
   return;
}

int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(ob->query_skill("sanshou-strike",1)<160||
      !ob->query("dtsl_quest_ssbp_ok")){
     command("say �����˼����������ˣ���Ҳ���ѵ�һ������");
     return 1;
   }
   if(ob->query("perform_quest/bapu")){
     command("say �������Ѿ�����������˼ҵľ���ɢ�ְ��˵ľ��裬���ǹ�ϲ��");
     return 1;
   }
   command("say ǰ������������һ�����Ÿ��ң�����ת�����㡣");
   ob->do_command("thank "+query("id"));
   message_vision("$N�ӹ����ſ���������������������\n",ob);
   ob->do_command("smile");
   ob->set("perform_quest/bapu",1);
   return 1;
}
