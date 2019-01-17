
inherit NPC;
#include <ansi.h>

string do_quest();

void create()
{
   set_name("����",({ "zhu chi","zhu","chi"}) );
        set("gender", "����" );
        set("age", 32);
        set("inquiry",([
          "����ӡ":(:do_quest:),
          ]));
    setup();
   carry_object(__DIR__"obj/sengyi")->wear();
  
}

void recover_object(object ob)
{
   ob->set("combat_exp",6000000);
   ob->set("str",40);
   ob->set("attitude", "peaceful");
   ob->set_skill("unarmed",350);
   ob->set_skill("cuff",350);
   ob->set_skill("finger",350);
   ob->set_skill("dodge",350);
   ob->set_skill("parry",350);
   ob->set_skill("force",350);
   ob->set_skill("strike",350);
   ob->set_skill("blade",350);
   ob->set_skill("literate",350);
   ob->set_skill("tianyi-xuangong",350);
   ob->set_skill("huanmo-shenfa",350);
   ob->set_skill("zhehua-baishi",350);
   ob->set_skill("baihua-zhang",350);
   ob->set("max_gin",6000);
   ob->set("eff_gin",6000);
   ob->set("gin",6000);
   ob->set("max_sen",6000);
   ob->set("eff_sen",6000);
   ob->set("sen",6000);
   ob->set("max_kee",6000);
   ob->set("eff_kee",6000);
   ob->set("kee",6000);
   ob->set("max_force",6000);
   ob->set("force",6000);
   ob->set("jiali",100);
   ob->set("max_pot",316);
   ob->reset_action();
   call_out("do_mask",300,ob);
   return;
}

int accept_object(object who,object ob)
{
  if(!ob->query("dtsl_quest_bsy"))
  return notify_fail("����˫�ֺ�ʮ�����Ĳ�Ҫ��Ķ�����\n");
 if(who->query("family/family_name")!="������"){
  
  if(!arrayp(who->query_temp("apply/name"))||
   (arrayp(who->query_temp("apply/name"))&&
   member_array("��ϣ��",who->query_temp("apply/name"))==-1&&
   member_array("������",who->query_temp("apply/name"))==-1) ){
   	
   recover_object(this_object());
   message_vision(HIR"$N��ɫһ������֪��������̫���ˣ�\n"NOR,this_object());
   kill_ob(who);
   return 1;
  }
  else{
    message_vision("$N��Ц�����������ڴˣ�����������ʲô����\n",this_object());
    who->set_temp("dtsl_quest_bsy/step1",1);
    return 1;
  }
 }
 
   
   message_vision("$N��Ц�����������ڴˣ�����������ʲô����\n",this_object());
   who->set_temp("dtsl_quest_bsy/step1",1);
   return 1;
}
   
string do_quest()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("dtsl_quest_bsy/step1")||
     ob->query("perform_quest/zhi")||
     ob->query("execute_quest/busiyin_fail"))
  return "ʩ����˵ʲô�������Ŀ���һ��Ҳ��������\n";
  ob->delete_temp("dtsl_quest_bsy/step1");
  ob->set_temp("dtsl_quest_bsy/step2",1);
  
  return "��Ȼ��ˣ���ȥ���ҵ�Ů��ʯ��诰ɣ�����ӡ���Ѿ��������ˣ�\n";
}

void do_mask(object ob)
{
  
   ob->set("combat_exp",60);
   ob->set("str",10);
   ob->set("attitude", "peaceful");
   ob->delete_skill("unarmed");
   ob->delete_skill("cuff");
   ob->delete_skill("finger");
   ob->delete_skill("dodge");
   ob->delete_skill("parry");
   ob->delete_skill("force");
   ob->delete_skill("strike");
   ob->delete_skill("blade");
   ob->delete_skill("literate");
   ob->delete_skill("tianyi-xuangong");
   ob->delete_skill("huanmo-shenfa");
   ob->delete_skill("zhehua-baishi");
   ob->delete_skill("baihua-zhang");
   ob->set("max_gin",100);
   ob->set("eff_gin",100);
   ob->set("gin",100);
   ob->set("max_sen",100);
   ob->set("eff_sen",100);
   ob->set("sen",100);
   ob->set("max_kee",100);
   ob->set("eff_kee",100);
   ob->set("kee",100);
   ob->set("max_force",100);
   ob->set("force",100);
   ob->set("jiali",0);
   ob->set("max_pot",100);
   ob->reset_action();
  return;
  
}
