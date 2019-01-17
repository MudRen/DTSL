
inherit JOBNPC;

#include <ansi.h>
#include <job_money.h>

void create()
{
	set_name("������",({"man"}));
	set("gender", "����" );
	set("long","����һ���������ᱦ��Ľ�������\n");
	set("nickname","�ᱦ���");
	set("age", 32);
    set("combat_exp", 100000);
	set("str", 30);
    set("max_gin",800);
    set("max_kee",800);
    set("max_sen",800);
    set("max_force",1000);
	set("force",1000);
    set("jiali",2);
   
  
 setup();
}

int kill_object(object killer,object victim)
{
  message_vision("$N��Ц�����������ᱦ����˾�������³�����������\n",killer);
  message_vision("$N����һ�Σ��ټ�������\n",killer);
  destruct(killer);
  return 1;
}

int set_status(object ob)
{
   
   JOBNPC_D->set_timejob_killer(this_object(),ob);
   return 1;
}

int clear()
{
  if(time()-query("last")<1000)
  return 0;
  if(!query("no_msg")){
  message_vision("$N�Ҵ����ˡ�\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void dispear()
{
   destruct(this_object());
   return;
}

int chat()
{
   
   if(clear())
   return 1;
   
   return ::chat();
}

void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   
   if(!ob||
   query("target_id")!=ob->query("id"))
   return ::die();
   
   ob->set_temp("killed_fyz_killer",1);
   
   return ::die();
}
