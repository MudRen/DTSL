
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ǻ�����һ��紵����������ɬ����Ϣ����˵��������������
����˽�Σ������кܶ�ٱ�������Ѳ�ӡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"haibin3",
 "southwest":__DIR__"haibin1",
        ]));
  set("objects",([
     __DIR__"npc/guanbing":2,
     ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
   object ob;
   if(me->query("gender")=="Ů��"&&me->query_per()>26
     &&present("guan bing",environment(me))
     &&me->query("family/family_name")!="�Ⱥ���ի")
     tell_object(me,"�ٱ���Ц��:"+RANK_D->query_respect(me)+"���ò����\n");
   if(objectp(ob=present("guan bing",environment(me)))&&
      me->query("gender")=="����"&&random(10)>5)
    { 
      switch(MONEY_D->player_pay(me,30) ){
      	case 0:
      	case 2: return notify_fail("�ٱ��ߵ���ûǮ��ûǮ�ͱ��ȥ�ˣ�\n");
          }
       message_vision("�ٱ�������$N������ʮ��ͭǮ��\n",me);
       
     }
    return ::valid_leave(me,dir);
}