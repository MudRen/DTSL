
inherit NPC;
#include <ansi.h>

int do_action1();

void create()
{
   object *ob;
   int i;
   
   set_name("ʯ��",({ "shi long","shi","long"}) );
   set("gender", "����" );
   set("title","��ɽ��");
   set("age", 32);
   set("long","���Ǿ��������书��ߵ�ʯ����\n");
   set("max_kee",600);
   set("max_gin",100);
   set("max_sen",100);
   set("max_force",100);
   set("force",100);
   set("combat_exp",1);
   set("inquiry",([
      "������":(:do_action1:),
      ]));
    setup();
   
   ob=children(__DIR__"tianwen");
   for(i=0;i<sizeof(ob);i++)
    if(objectp(ob[i])&&environment(ob[i]))
     destruct(ob[i]);
  
}

int do_action1()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query("dtsl_quest_csj_help_ok")){
    command("say �ҿ�û�����������");
    return 1;
  }
  
  command("say ��Ȼ�������ҵ����ܣ��Ҳ������»���ˣ�");
  ob->set_temp("kill_shilong",1);
  ob->set("dtsl_quest_csj_help_ok",1);
  kill_ob(ob);
  return 1;
}

int chat()
{
  object ob,target;
  
  ob=query_temp("last_damage_from");
  
  if(!ob||!ob->query_temp("kill_shilong"))
   return ::chat();
   
  if(query("eff_kee")*100/query("max_kee")<20){
     target=new(__DIR__"tianwen");
     target->move("/d/yangzhou/guangchang");
     command("say �ߣ��㻹���е㱾�£���");
     message_vision("$Nһת�����ˣ���\n",this_object());
     destruct(this_object());
     return 1;
  }
  return ::chat();
}