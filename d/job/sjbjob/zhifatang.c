
#include <ansi.h>
#include <job_money.h>
inherit ROOM;

string give_job();
int do_ok(string arg);

string *dir1=({
"/d/wuyishan"
});

string *dir2=({
"/d/taishan","/d/huashan"
});

string *dir3=({
"/d/emeishan","/d/suiye","/d/dingxiang"
});

void create ()
{
  set ("short",HIR"ִ����"NOR);
  set ("long", @LONG
�������μұ���ִ���á��μұ��ĵ��ӷ��˴��󣬶�Ҫ����������
�ܴ�����������Щ�����Ѿ������μұ�����ͽ�������ӵ������ط�����
�ұ�һֱ��ץ����Щ��ͽ��������ͽ�����ֶ�д�ڹ���ǽ�ϵ����Ŵ��
(bang)�ϡ�
LONG);

  set("exits", ([ 

   "north":"/d/lingnan/modaotang",
       ]));
  set("item_desc",([
	  "bang":(:give_job:),
    ]));

  set("valid_startroom", 1);
 
  setup();
 
}

void init()
{
  add_action("do_ok","task");
}

string give_job()
{
  object ob,killer;
  string *dirs,str;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<100000)
  return "����С���һ�ߴ���ȥ��\n";
  
  if(ob->query_temp("song_kill_pantu_msg"))
  return ob->query_temp("song_kill_pantu_msg");
  if(time()-ob->query("busy_time")<40+random(5))
  return "�㿴�˿����������滹û����ͽ���������֡�\n";
  if(ob->query_temp("dtsl_job"))
   return "������������������æ�����İɣ�\n";
   if(!valid_do_job(ob,"song"))
	return "����书�ܸ��ˣ���������С�����Ǵ��С���ˣ�\n";
  
  if(ob->query("combat_exp")<500000)
    dirs=dir1;
  else
  if(ob->query("combat_exp")<900000)
    dirs=dir1+dir2;
  else
    dirs=dir1+dir2+dir3;
    
  killer=new(__DIR__"killer");
  
  if(!killer->set_status(ob))
   return "��ͽ�������ˣ���ȥ������ʦ��\n";
  
  if(!random_place(killer,dirs))
   return "������ּ���Щģ�����塣\n";
  
  if(!environment(killer))
   return "������ּ���Щģ�����塣\n";
  	
   ob->set_temp("dtsl_job","�μұ�ɱ��ͽ����");  
   ob->set_temp("song_kill_pantu",1);
  str=
  "             "+HBMAG+"�μұ���ͽ��"+NOR+"\n"+ 
  YEL"**************************************\n"NOR+
  "\n\n      "+MISC_D->find_place(environment(killer))+"\n"+
  "\n      "+killer->name()+"\n\n\n"+
  YEL"**************************************\n\n\n\n"NOR;
  ob->set_temp("song_kill_pantu_msg",str);
  ob->add_temp_array("job_temp_killer",killer);
  return str;
}

int do_ok(string arg)
{
  object ob;
  
  ob=this_player();
  if(!arg||arg!="ok")
  return notify_fail("ʲô��\n");
  if(!ob->query_temp("song_kill_pantu"))
  return notify_fail("ʲô��\n");
  if(!ob->query_temp("song_kill_pantu_ok"))
  return notify_fail("û��ɱ����ͽ����ô�ͻ��������ˣ�\n");
  ob->delete_temp("song_kill_pantu");
  ob->delete_temp("song_kill_pantu_ok");
  ob->delete_temp("song_kill_pantu_msg");
  ob->delete_temp("dtsl_job");
  ob->set("busy_time",time());
  
  JOBSYS_D->give_reward_sjbkillpantu(ob);
  
 return 1;
}
