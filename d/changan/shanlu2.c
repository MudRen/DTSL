
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·��������ï�ܵĲݴԣ����Ｘ��û��ʲô�ˣ�����
�紵��������Զ��������˻����������ֻ������һ����ֻ��һֻҰ�ô�
�ԱߵĲݴ������˳�����
LONG);

  set("exits", ([ 
"northwest":__DIR__"shanlu1",
"southeast":__DIR__"tulu1",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

