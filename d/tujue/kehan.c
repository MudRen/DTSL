

inherit NPC;

#include <ansi.h>
#include <job_money.h>

int do_action1();

void create()
{
   set_name("�����",({ "da han","da","han" }) );
   set("gender", "����" );	
   set("age", 50);
   set("combat_exp",1000000);
   set("str", 25);
   set("per", 22);
   
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("whip",200);
   set_skill("literate",200);
  
   set_skill("yanyang-dafa",200);
   set_skill("canglang-jue",200);
   set_skill("youlong-shenfa",200);
   set_skill("feiwo-whip",200);
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   set("inquiry",([
    "���α޷�":(:do_action1:),
    ]));
   create_family("ͻ��",2,"��");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/whip")->wield();
  
}

string *dirs=({
"/d/saiwai",
});

int do_action1()
{
  object ob,horse;
  
  ob=this_player();
  
  if(ob->query("tujue_jun")!="���Ǿ�"){
         command("say ��û�������ǽ��Ǿ������ǲ���������κ��ؾ��ģ�");
         return 1;
  }
  if(ob->query("perform_quest/kun")){
     command("say ���Ѿ������˷��α޷��ľ��ϣ��Լ�ȥ�ú���߰ɣ�");
     return 1;
  }
  if(ob->query("perform_quest/kuangsha")){
     command("say ���Ѿ������˿�ɳ�����ľ��ϣ��޷������α޷��ľ��ϣ�");
     return 1;
  }
  if(ob->query_skill("feiwo-whip",1)<160){
    command("say ��ķ��α޷���Ϊ̫�ͣ��޷�������еľ���֮����");
    return 1;
  }
  if(ob->query_temp("perform_quest/kun_action1")){
     command("say ���ȥ�����Һ�Ѫ����ɣ�");
     return 1;
  }
  horse=new(__DIR__"horse");
  horse->set_status(ob);
  if(!random_place(horse,dirs)){
    command("say ��ȵ�... ...");
    return 1;
  }
  if(!environment(horse)){
    command("say ��ȵ�... ...");
    return 1;
  }
  ob->set_temp("perform_quest/kun_action1",1);
  ob->add_temp_array("job_temp_killer",horse);
  command("say ��˵��"+MISC_D->find_place(environment(horse))+"��һֻ��Ѫ������ȥ���Ҵ����ɣ�");
  
  return 1;
}

int accept_object(object ob,object obj)
{
   if(!ob->query_temp("perform_quest/kun_action1"))
   return 0;
   if(!obj->query("perform_quest_kun_obj"))
   return 0;
   if(obj->query("owner_ob")!=ob)
   return notify_fail("����������ץ����ֻ����\n");
   
   ob->delete_temp("perform_quest/kun_action1");
   command("pat "+ob->query("id"));
   command("say �ã��ɵĲ�������ʹ�������α޷��ľ���֮����");
   message_vision("$N�յ�$n���ߵ��Ｘ�䣬$n��������\n",this_object(),ob);
   ob->set("perform_quest/kun",1);
   return 1;
}