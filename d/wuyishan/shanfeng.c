
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
����������ɽ��һ��ɽ�塣������ãã����ȡ������￴ȥ������
ɽ�����ķ�⾡���۵ף�һ�ɺ�׳�ĸо���Ȼ������
LONG);

  set("exits", ([ 

   "west":__DIR__"shulin3",
    
          ]));
set("objects",([
 "/d/clone/npc/beast/shanyang":1,
]));
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

