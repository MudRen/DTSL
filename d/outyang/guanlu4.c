
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
������һ�����Ĺ�·���ϱ߾������ݵı����ˡ����������ԹŶ�
�Ƿ����ĳ��У��������･��������������ֻ���ܶ����˳��ϱߵı���
ӿȥ��
LONG);

  set("exits", ([ 
 "north":__DIR__"guanlu3",
 "south":"/d/yangzhou/beimen",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

