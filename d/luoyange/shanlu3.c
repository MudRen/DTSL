
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ������ȥ��ɽ·��������һ�����ţ���������ɽ�ıؾ�֮
���ˡ����������Ƿ�������������ˡ�
LONG);

  set("exits", ([ 
  "southeast":__DIR__"caoyuan",
  "northwest":"/d/feima-muchang/bridge",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

