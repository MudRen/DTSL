
#include <ansi.h>
inherit ROOM;

int do_pa();
void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
������һɽ�£��ǳ���б��һ��С�ģ��Ϳ��ܹ��������档������
һ����ɽ��·��������һ��ɽ��������ûʲô·�ߣ�ֻ����(pa)��ȥ�ˡ�
LONG);

  set("exits", ([ 

   "eastup":__DIR__"shanlu4",
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
   me->move(__DIR__"shanji2");
   message_vision("$N��׼һ���ط�����˫��ץס��������ȥ��\n",me);
   tell_object(__DIR__"shanji2",me->name()+"����������\n");
   return 1;
}
