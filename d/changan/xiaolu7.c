
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","������С·");
  set ("long", @LONG
������һ�����ų�����ǽ������С·������û��ʲô�ˣ��ǳ��ľ���
ֻ������������Ľ����������Ǹ߸ߵĳ�ǽ����ǽ������ǳ������ˡ�
̧ͷ��ȥ������ԼԼ���Կ���һЩȫ����װ�Ĺٱ����ڳ�ͷһ˿������վ
��ֵ�ڡ�
LONG);

  set("exits", ([ 
"north":__DIR__"dongmen",
"south":__DIR__"yanxingmen",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

