
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","�ϳ���С·");
  set ("long", @LONG
������һ�����ų�����ǽ������С·������û��ʲô�ˣ��ǳ��ľ���
ֻ������������Ľ����������Ǹ߸ߵĳ�ǽ����ǽ������ǳ������ˡ�
̧ͷ��ȥ������ԼԼ���Կ���һЩȫ����װ�Ĺٱ����ڳ�ͷһ˿������վ
��ֵ�ڡ�
LONG);

  set("exits", ([ 
"west":__DIR__"mingdemen",
"east":__DIR__"qixiamen",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

