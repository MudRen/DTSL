
#include <ansi.h>
inherit ROOM;
int do_pa();
void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·�����߾����վ��Ĵ��ɽ�ˡ�̧ͷ��ȥ�����ɽ��
ʯ��ᾣ�������������ȴ��������û��ʲô·��Ҫ����ȥ��ֻ����(pa)�ˡ�
LONG);

  set("exits", ([ 

   "west":"/d/xiangyang/tulu3",
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
   me->add("sen",-15);
   message_vision("$N��׼һ���ط�����˫��ץס��������ȥ��\n",me);
   tell_room(__DIR__"shanji2",me->name()+"����������\n");
   me->move(__DIR__"shanji2");
   return 1;
}
