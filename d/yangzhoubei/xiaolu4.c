
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·�����߲�Զ��������ʦ�ˡ���ʱ��������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG);

  set("exits", ([ 
 "east":__DIR__"xiaolu3",
 "west":"/d/luoyange/xiaolu3",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

