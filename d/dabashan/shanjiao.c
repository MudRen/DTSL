
#include <ansi.h>
inherit ROOM;

int do_pa();
void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
�����Ǵ��ɽ��ɽ���¡����ɽ���վ����ƣ����Է������ɽҲ��
һ��ʮ�ֲ����׵��¡�ֻ����ǰ��ʯ��ᾣ��շ����������Ϊһ�յء�
��ǰû��ʲô·��������ֻ��������(pa)�ˡ�
LONG);

  set("exits", ([ 

   "east":"/d/xiangyang/tulu2",
       ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_pa","pa");
}

int do_pa()
{
   object me;
   me=this_player();
   if(me->query("sen")<15)
   return notify_fail("����ͼ����ȥ�����Ǿ���ƣ�룬����ʹ���ϰ��������\n");
 if(me->query_temp("track"))
 return notify_fail("���������γ�������������ȥ��\n");
   me->add("sen",-15);
   message_vision("$N��׼һ���ط�����˫��ץס��������ȥ��\n",me);
   tell_room(__DIR__"shanji1",me->name()+"����������\n");
   me->move(__DIR__"shanji1");
   return 1;
}
