
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ�����Ĺ�·���ϱ߾������ݵı����ˡ�����������Ѿ�
�ܶ��ˡ����･��������������ֻ���ܶ����˳��ϱߵı���ӿȥ��
LONG);

  set("exits", ([ 
 "north":__DIR__"dalu2",
 "south":__DIR__"guanlu4",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

