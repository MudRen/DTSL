
inherit NPC;

#include <ansi.h>
#include <job_money.h>


mapping here=([
"������":"/d/lingnan/bingqishi",
"��Ϣ��":"/d/lingnan/xiuxishi",
"ĥ����":"/d/lingnan/modaotang",
"���﷿":"/d/lingnan/huowufang",
]);

string give_job();
int do_ok(string arg);
int cancel_job();

void create()
{
   set_name("������",({ "song popo","song","popo" }) );
        set("gender", "Ů��" );
		
        set("age", 70);
   set("long", "�������μұ����ӻ�������ţ������Ѹ��ˡ�\n");
       
   set("combat_exp", 50000);
   set("str", 25);
   set("attitude", "peaceful");
   set_skill("blade",30);
   set_skill("tiandao-bajue",30);
   set_skill("dodge",30);
   set_skill("force",30);
   set("force",200);
   set("target_id","###");
   set("inquiry",([
      "job":(:give_job:),
      "����":(:cancel_job:),
      ]));
   setup();
  
}

void init()
{
   add_action("do_ok","task");
}

string give_job()
{
  object ob,tool;
  string *where;
  int i;
  
  ob=this_player();
  
   if(ob->query("family/family_name")!="�μұ�")
   return "ֻ���μұ��ĵ��Ӳſ������������\n";
   
   if(ob->query("combat_exp")>=100000)
   return "ƾ����������������������ǿ�ϧ�ˣ�\n";
   
   if(ob->query_temp("sjb_saochu"))
   return "�����¿�Ҫ��ͷ��β����Ҫ���������\n";
   
   if(time()-ob->query("busy_time")<10+random(10))
   return "���������ºαؼ���һʱ�أ�������Ъ��ɣ�\n";
   
   if(ob->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   
   ob->set_temp("dtsl_job","�μұ���������");
   ob->set_temp("sjb_saochu",1);
   
   where=keys(here);
   i=random(sizeof(where));
   
   tool=new(__DIR__"tool");
   tool->set("owner",ob);
   tool->set("place",here[where[i]]);
   
   tool->move(ob);
   ob->add_temp_array("job_temp_killer",tool);
   tell_object(ob,query("name")+"������һ��"+tool->name()+"��\n");
   return "�ðɣ��鷳��ȥ"+where[i]+"��ɨһ�������ɣ�\n";
}

int do_ok(string arg)
{
   object ob,target;
   string paper_name;
   
   ob=this_player();
   
   if(!arg||sscanf(arg,"ok with %s",paper_name)!=1)
   return notify_fail("���ʹ�� task ok with xx �����\n");
   if(!ob->query_temp("sjb_saochu"))
  return notify_fail("��û����"+query("name")+"Ҫ�������\n");
   if(!objectp(target=present(paper_name,ob)))
   return notify_fail("������û�����������\n");
   if(target->query("owner")!=ob)
  return notify_fail("�ⲻ�����ɨ�㣡\n");
   if(!target->query("ok"))
   return notify_fail("�㻹û��������ȥɨ���ɣ�\n");
   
  tell_object(ob,query("name")+"�������ͷ���ã��ɵò���\n");
  target->unequip();
  destruct(target);
   
   JOBSYS_D->give_reward_sjbzahuo(ob);
   
   ob->delete_temp("sjb_saochu");
   ob->delete_temp("sjb_saochu_times");
   ob->delete_temp("dtsl_job");
   ob->set("busy_time",time());
   return 1;
}

int cancel_job()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("sjb_saochu")){
  
  command("?");
  return 1;
  }
  JOBSYS_D->do_cancel_job("sjbzahuo",ob,this_object());
  
  command("say ���С���㶼�����ã��Ժ���ô������������\n");
  return 1;
}
