
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","��·");
  set ("long", @LONG
������һ����·���˴��ǹʵ��ųأ������������������ڴˡ�����
���Ѳ����ɾ����������飬������Ӣ�����겻�ѡ�
LONG);

  set("exits", ([ 
"northwest":__DIR__"shalu2",
"east":__DIR__"lguanlu2",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

