
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
��������Ժ������Ϣ�ĵط������ϵı�������������룬�м�����
������������˯�����������ﲻ����Щ���ˡ�
LONG);

  set("exits", ([ 
	  "west":__DIR__"caodi3",
       ]));

  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

int do_sleep(object ob)
{
   object obj;
   
   if(!ob->query_temp("try_bai_butan_actoin1"))
   return 1;

   obj=new(__DIR__"obj/jinfo");
   obj->move(ob);
   tell_object(ob,"\n��ͻȻ������һ�������æ����������\n\n");
   ob->delete_temp("try_bai_butan_actoin1");
   ob->set_temp("try_bai_butan_actoin2",1);
   return 1;
}