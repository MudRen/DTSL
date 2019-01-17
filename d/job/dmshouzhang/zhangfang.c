//job.
// ������������
//150k-200k û��ɱ��
//200k �Ժ���ɱ�֡�
#include <job_money.h>
#include <ansi.h>
inherit NPC;


mapping target=([
"/d/yangzhou/npc/tiejiang":"��������","/d/hangzhou/npc/tiejiang":"��������",
"/d/baling/npc/tiejiang":"��������","/d/jiujiang/npc/tiejiang":"�Ž�����",
"/d/chengdu/npc/tiejiang":"�ɶ�����",
"/d/hefei/npc/tiejiang":"�Ϸ�����","/d/xiangyang/npc/tiejiang":"��������",
]);

string give_job();
int do_ok(string arg);
int cancel_job();

void create()
{
   set_name("�˷�����",({ "xian sheng","xian","sheng" }) );
        set("gender", "����" );
        set("age", 42);
set("target_id","####");
   set("long", "���Ƕ�����˷�������\n");
   set("combat_exp", 600000);
   set("str", 30);
   set_temp("apply/armor",30);
   set_temp("apply/damage",30);
   set_temp("apply/dodge",30);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("max_force",2000);
   set("force",2000);
   set("inquiry",([
     "����":(:give_job:),
     "����":(:cancel_job:),
     ]));
   setup();
  
}

void init()
{
  add_action("do_ok","jiaochai");
}

int cancel_job()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("dm_shouzhang")){
  command("kok "+ob->query("id"));
  return 1;
  }
  if(present("zhang ben",ob))
  destruct(present("zhang ben",ob));
  
  JOBSYS_D->do_cancel_job("dmshouzhang",ob,this_object());
  
  return 1;
}

string give_job()
{
  object me;
  object ob;
  string *t;
  string t_name;
  int i;
  
  me=this_player();
  
  if(me->query("combat_exp")<100000)
  return "��Ĺ���̫���ˣ��������������ġ�\n";
  if(me->query_temp("dm_shouzhang"))
  return "�㻹�ǸϽ�ȥ�ɣ������������������Ҳ��������ġ�\n";
  if(time()-me->query("busy_time")<40+random(10))
  return "�㻹����ЪЪ�ɣ�\n";
  if(me->query_temp("dtsl_job")&&
    me->query_temp("dtsl_job")!="��������������")
  return "���������������񣬻�����æ�������İɣ�\n";
  
  me->set_temp("dm_shouzhang",1);
  me->set_temp("dtsl_job","��������������");
  
  t=keys(target);
  i=random(sizeof(t));
  t_name=t[i];
  me->set_temp("dm_shouzhang_target",t[i]);
  ob=new(__DIR__"book");
  ob->set("dm_shouzhang_target",t[i]);
  ob->move(me);
  return "�ð�,"+target[t[i]]+"��������������������ȥ�������˰ɣ�\n";

}



int do_ok(string arg)
{
  object ob;
  object target;
  string name;
  
  
  ob=this_player();
  if(!ob->query_temp("dm_shouzhang"))
  return 0;
  if(!arg||sscanf(arg,"with %s",name)!=1)
  return notify_fail("��ʹ�� jiaochai with xxx �����\n");
  if(!objectp(target=present(name,ob)))
  return notify_fail("������û�����������\n");
  if(!target->query("dm_shouzhang_ok"))
  return notify_fail("��úÿ��������˱�����ĿҲ���԰�����\n");
  
  ob->delete_temp("dm_shouzhang");
  ob->delete_temp("dm_shouzhang_target");
  ob->delete_temp("dtsl_job");
  ob->set("busy_time",time());
  
  destruct(target);
  tell_object(ob,""+query("name")+"���˱�����������\n");
  
  JOBSYS_D->give_reward_dmshouzhang(ob);
  return 1;
}
